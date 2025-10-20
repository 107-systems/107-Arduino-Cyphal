/// This software is distributed under the terms of the MIT License.
/// Copyright (c) 2020 UAVCAN Development Team.
/// Authors: Pavel Kirienko <pavel.kirienko@zubax.com>, Tom De Rybel <tom.derybel@robocow.be>

// This is needed to enable the necessary declarations in sys/
#ifndef _GNU_SOURCE
#    define _GNU_SOURCE
#endif

#include "socketcan.h"

#ifdef __linux__
#    include <linux/can.h>
#    include <linux/can/raw.h>
#    include <net/if.h>
#    include <sys/ioctl.h>
#    include <sys/socket.h>
#    include <linux/net_tstamp.h>
#    include <linux/errqueue.h>
#else
#    error "Unsupported OS -- feel free to add support for your OS here. " \
        "Zephyr and NuttX are known to support the SocketCAN API."
#endif

#include <assert.h>
#include <errno.h>
#include <poll.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define KILO 1000L
#define MEGA (KILO * KILO)
#define NANOSECONDS_PER_SECOND 1000000000LL
#define NANOSECONDS_PER_MICROSECOND 1000LL

static int16_t getNegatedErrno(void)
{
    const int out = -abs(errno);
    if (out < 0)
    {
        if (out >= INT16_MIN)
        {
            return (int16_t) out;
        }
    }
    else
    {
        assert(false);  // Requested an error when errno is zero?
    }
    return INT16_MIN;
}

/**
 * A wrapper function for the ppoll() system call.
 *
 * This function waits for a specific event (or timeout) on a single file descriptor (fd).
 *
 * @param fd      The file descriptor (socketcan handle) to poll.
 * @param mask    A bitmask specifying the events we are interested in (e.g., POLLIN, POLLOUT).
 * @param timeout_usec The maximum time to wait for an event, in microseconds.
 *
 * @return 1 on success (the requested event occurred).
 * @return 0 on timeout (no event occurred within the time limit).
 * @return < 0 on error (a negative errno value).
 */
static int16_t doPoll(const SocketCANFD fd, const int16_t mask, const CanardMicrosecond timeout_usec)
{
    struct pollfd fds;
    memset(&fds, 0, sizeof(fds));
    fds.fd     = fd;
    fds.events = mask;

    struct timespec ts;
    ts.tv_sec  = (long) (timeout_usec / (CanardMicrosecond) MEGA);
    ts.tv_nsec = (long) (timeout_usec % (CanardMicrosecond) MEGA) * KILO;

    const int poll_result = ppoll(&fds, 1, &ts, NULL);
    // A negative result from poll indicates a system error (e.g., bad memory address).
    if (poll_result < 0) {
        return getNegatedErrno();
    }

    // timeout expired without any of the requested events happening.
    if (poll_result == 0) {
        return 0;
    }

    // If we get here, means an event did happen.
    // The kernel has updated 'fds.revents' to tell us what it was.
    const uint32_t revents = (uint32_t)fds.revents;

    // Did we request to check for data available to read?
    if (((uint32_t)mask & (uint32_t)POLLIN) != 0) {

        // Check if data available to read
        if ((revents & (uint32_t)POLLIN) != 0) {
            // printf("Data available to read\n");
            return 1;
        }

        // Check if error queue contains data
        if ((revents & (uint32_t)POLLERR) != 0) {
            // printf("Error queue contains data\n");
            return 1;  // errqueue wakes here
        }
    }

    // Did we request to check for ability to write data?
    if (((uint32_t)mask & (uint32_t)POLLOUT) != 0) {

        // Check if writing to the Socket will not block (buffer space available)
        if ((revents & (uint32_t)POLLOUT) != 0) {
        return 1;
      }
    }

    // This block catches any error events.
    // POLLHUP  = "Poll Hang Up". The other end disconnected.
    // POLLNVAL = "Poll Invalid". The file descriptor is invalid (e.g., closed).
    if (revents & ((uint32_t)POLLERR | (uint32_t)POLLHUP | (uint32_t)POLLNVAL)) {
        int soerr = 0;
        socklen_t slen = sizeof(soerr);

        if (getsockopt(fd, SOL_SOCKET, SO_ERROR, &soerr, &slen) == 0 && soerr != 0) {
            errno = soerr;
            return getNegatedErrno();
        }
        return -EIO;
    }

    return -EIO;
}

/**
 * Convert a timespec structure to nanoseconds.
 *
 * @param ts The timespec structure to convert.
 *
 * @return The equivalent time in nanoseconds.
 */
static inline int64_t timespecToNanoseconds(const struct timespec* ts)
{
    return ((int64_t)ts->tv_sec * NANOSECONDS_PER_SECOND) + (int64_t)ts->tv_nsec;
}

/**
 * Parse the timestamping control message from a received socket message.
 * @param msg The message header containing control messages.
 * @param tss_out An array to store the extracted timestamps.
 *
 * @return true if the timestamping control message was found and parsed, false otherwise.
 */
static inline bool parseTimestampingCmsg(const struct msghdr* msg, struct timespec tss_out[3])
{
    for (struct cmsghdr* c = CMSG_FIRSTHDR((struct msghdr*)msg); c; c = CMSG_NXTHDR((struct msghdr*)msg, c)) {
        if (c->cmsg_level == SOL_SOCKET && c->cmsg_type == SCM_TIMESTAMPING) {
            (void)memcpy(tss_out, CMSG_DATA(c), sizeof(struct timespec[3]));
            return true;
        }
    }
    return false;
}

static inline bool parseTxIDFromErrqueue(const struct msghdr* msg, uint32_t* out_id)
{
    for (struct cmsghdr* c = CMSG_FIRSTHDR((struct msghdr*)msg); c; c = CMSG_NXTHDR((struct msghdr*)msg, c)) {
        if (c->cmsg_len >= CMSG_LEN(sizeof(struct sock_extended_err))) {
            struct sock_extended_err se;
            memcpy(&se, CMSG_DATA(c), sizeof(se));

            if (se.ee_origin == SO_EE_ORIGIN_TIMESTAMPING) {
                if (out_id) {
                    *out_id = se.ee_data;
                }
                return true;
            }
        }
    }
    return false;
}

SocketCANFD socketcanOpen(const char* const iface_name, const bool can_fd,
                          const bool en_rx_timestamping, const bool en_tx_timestamping,
                          const bool enable_frame_reception)
{
    const size_t iface_name_size = strlen(iface_name) + 1;
    if (iface_name_size > IFNAMSIZ)
    {
        return -ENAMETOOLONG;
    }

    const int fd = socket(PF_CAN, SOCK_RAW | SOCK_NONBLOCK, CAN_RAW);  // NOLINT
    bool      ok = fd >= 0;

    if (ok)
    {
        struct ifreq ifr;
        (void) memset(&ifr, 0, sizeof(ifr));
        (void) memcpy(ifr.ifr_name, iface_name, iface_name_size);
        ok = 0 == ioctl(fd, SIOCGIFINDEX, &ifr);
        if (ok)
        {
            struct sockaddr_can addr;
            (void) memset(&addr, 0, sizeof(addr));
            addr.can_family  = AF_CAN;
            addr.can_ifindex = ifr.ifr_ifindex;
            ok               = 0 == bind(fd, (struct sockaddr*) &addr, sizeof(addr));
        }
    }

    // Enable CAN FD if required.
    if (ok && can_fd)
    {
        const int en = 1;
        ok           = 0 == setsockopt(fd, SOL_CAN_RAW, CAN_RAW_FD_FRAMES, &en, sizeof(en));
    }

    // Enable or disable frame reception for this socket.
    if (ok && !enable_frame_reception) {
        setsockopt(fd, SOL_CAN_RAW, CAN_RAW_FILTER, NULL, 0);
    }

    // Enable timestamping.
    if (ok) {
        unsigned int ts_flags =
            (en_rx_timestamping ? (unsigned int)SOF_TIMESTAMPING_RX_HARDWARE |
                                  (unsigned int)SOF_TIMESTAMPING_RX_SOFTWARE
                                  : 0) |
            (en_tx_timestamping ? (unsigned int)SOF_TIMESTAMPING_TX_HARDWARE |
                                  (unsigned int)SOF_TIMESTAMPING_TX_SOFTWARE
                                  : 0) |
                                  (unsigned int)SOF_TIMESTAMPING_RAW_HARDWARE |
                                  (unsigned int)SOF_TIMESTAMPING_SOFTWARE |
                                  (unsigned int)SOF_TIMESTAMPING_OPT_TX_SWHW |
                                  (unsigned int)SOF_TIMESTAMPING_OPT_TSONLY |
                                  (unsigned int)SOF_TIMESTAMPING_OPT_ID;
        ok = 0 == setsockopt(fd, SOL_SOCKET, SO_TIMESTAMPING, &ts_flags, sizeof(ts_flags));
    }

    // Enable outgoing-frame loop-back.
    // if (ok)
    // {
    //     const int en = 1;
    //     ok           = 0 == setsockopt(fd, SOL_CAN_RAW, CAN_RAW_RECV_OWN_MSGS, &en, sizeof(en));
    // }

    if (ok)
    {
        return fd;
    }

    (void) close(fd);
    return getNegatedErrno();
}

int16_t socketcanPush(const SocketCANFD fd, const CanardFrame* const frame, const CanardMicrosecond timeout_usec)
{
    if ((frame == NULL) || (frame->payload == NULL) || (frame->payload_size > UINT8_MAX))
    {
        return -EINVAL;
    }

    const int16_t poll_result = doPoll(fd, POLLOUT, timeout_usec);
    if (poll_result > 0)
    {
        // We use the CAN FD struct regardless of whether the CAN FD socket option is set.
        // Per the user manual, this is acceptable because they are binary compatible.
        struct canfd_frame cfd;
        (void) memset(&cfd, 0, sizeof(cfd));
        cfd.can_id = frame->extended_can_id | CAN_EFF_FLAG;
        cfd.len    = (uint8_t) frame->payload_size;
        // We set the bit rate switch on the assumption that it will be ignored by non-CAN-FD-capable hardware.
        cfd.flags = CANFD_BRS;
        (void) memcpy(cfd.data, frame->payload, frame->payload_size);

        // If the payload is small, use the smaller MTU for compatibility with non-FD sockets.
        // This way, if the user attempts to transmit a CAN FD frame without having the CAN FD socket option enabled,
        // an error will be triggered here.  This is convenient -- we can handle both FD and Classic CAN uniformly.
        const size_t mtu = (frame->payload_size > CAN_MAX_DLEN) ? CANFD_MTU : CAN_MTU;
        if (write(fd, &cfd, mtu) < 0)
        {
            return getNegatedErrno();
        }
    }
    return poll_result;
}

int16_t socketcanPop(const SocketCANFD        fd,
                     CanardFrame* const       out_frame,
                     CanardMicrosecond* const out_timestamp_usec,
                     const size_t             payload_buffer_size,
                     void* const              payload_buffer,
                     const CanardMicrosecond  timeout_usec,
                     bool* const              loopback)
{
    if ((out_frame == NULL) || (payload_buffer == NULL))
    {
        return -EINVAL;
    }

    const int16_t poll_result = doPoll(fd, POLLIN, timeout_usec);
    if (poll_result > 0)
    {
        // Initialize the message header scatter/gather array. It is to hold a single CAN FD frame struct.
        // We use the CAN FD struct regardless of whether the CAN FD socket option is set.
        // Per the user manual, this is acceptable because they are binary compatible.
        struct canfd_frame sockcan_frame = {0};  // CAN FD frame storage.
        struct iovec       iov           = {
            // Scatter/gather array items struct.
                            .iov_base = &sockcan_frame,        // Starting address.
                            .iov_len  = sizeof(sockcan_frame)  // Number of bytes to transfer.

        };

        // Determine the size of the ancillary data and zero-initialize the buffer for it.
        // We require space for both the receive message header (implied in CMSG_SPACE) and the time stamp.
        // The ancillary data buffer is wrapped in a union to ensure it is suitably aligned.
        // See the cmsg(3) man page (release 5.08 dated 2020-06-09, or later) for details.
        union {
          uint8_t buf[CMSG_SPACE(sizeof(struct timespec[3]))];
          struct cmsghdr align;
        } control;
        (void)memset(control.buf, 0, sizeof(control.buf));

        // Initialize the message header used by recvmsg.
        struct msghdr msg  = {0};                  // Message header struct.
        msg.msg_iov        = &iov;                 // Scatter/gather array.
        msg.msg_iovlen     = 1;                    // Number of elements in the scatter/gather array.
        msg.msg_control    = control.buf;          // Ancillary data.
        msg.msg_controllen = sizeof(control.buf);  // Ancillary data buffer length.

        // Non-blocking receive messages from the socket and validate.
        const ssize_t read_size = recvmsg(fd, &msg, MSG_DONTWAIT);
        if (read_size < 0) {
            // This can happen if poll() wakes on POLLERR but the error is cleared
            // before we call recvmsg(). Treat it as a non-event.
            if (errno == EAGAIN || errno == EWOULDBLOCK) {
                return 0;
            }
            return getNegatedErrno();  // Real error -> propagate
        }

        if ((read_size != CAN_MTU) && (read_size != CANFD_MTU))
        {
            return -EIO;
        }

        if (sockcan_frame.len > payload_buffer_size)
        {
            return -EFBIG;
        }

        const bool valid = ((sockcan_frame.can_id & CAN_EFF_FLAG) != 0) &&  // Extended frame
                           ((sockcan_frame.can_id & CAN_ERR_FLAG) == 0) &&  // Not Error frame
                           ((sockcan_frame.can_id & CAN_RTR_FLAG) == 0);    // Not RTR frame
        if (!valid)
        {
            return 0;  // Not an extended data frame -- drop silently and return early.
        }

        // Handle the loopback frame logic.
        const bool loopback_frame = ((uint32_t) msg.msg_flags & (uint32_t) MSG_CONFIRM) != 0;
        if (loopback == NULL && loopback_frame)
        {
            return 0;  // The loopback pointer is NULL and this is a loopback frame -- drop silently and return early.
        }

        if (loopback != NULL)
        {
            *loopback = loopback_frame;
        }

        // Obtain the CAN frame time stamp from the kernel.
        // This time stamp is from the CLOCK_REALTIME kernel source.
        if (out_timestamp_usec != NULL) {
            struct timespec tss[3] = {{0}};
            int64_t software_timestamp_ns = 0;

            // Extract the software timestamp from the control messages if present.
            if (parseTimestampingCmsg(&msg, tss)) {
                software_timestamp_ns = timespecToNanoseconds(&tss[0]);
            }

            // Fallback: If no software timestamp was found, get the system realtime.
            if (software_timestamp_ns == 0) {
                struct timespec ts_fallback = {0};
                if (clock_gettime(CLOCK_REALTIME, &ts_fallback) == 0) {
                    software_timestamp_ns = timespecToNanoseconds(&ts_fallback);
                }
            }
            *out_timestamp_usec = (CanardMicrosecond)(software_timestamp_ns / KILO);
        }

        out_frame->extended_can_id = sockcan_frame.can_id & CAN_EFF_MASK;
        out_frame->payload_size    = sockcan_frame.len;
        out_frame->payload         = payload_buffer;
        (void) memcpy(payload_buffer, &sockcan_frame.data[0], sockcan_frame.len);
    }
    return poll_result;
}

int16_t socketcanPopTimestamp(const SocketCANFD        fd,
                              const CanardMicrosecond  timeout_usec,
                              uint32_t* const          out_tx_id,
                              CanardMicrosecond* const out_sw_timestamp_usec,
                              CanardMicrosecond* const out_raw_hw_timestamp_usec)
{
    if (out_sw_timestamp_usec == NULL ||
        out_raw_hw_timestamp_usec == NULL) {
        return -EINVAL;
    }

    const int16_t poll_result = doPoll(fd, POLLIN, timeout_usec);
    if (poll_result <= 0) {
        return poll_result;
    }

    union {
        uint8_t buf[ CMSG_SPACE(sizeof(struct timespec[3])) +
                    CMSG_SPACE(sizeof(struct sock_extended_err)) + 64 ];
        struct cmsghdr align;
    } control;
    (void) memset(control.buf, 0, sizeof(control.buf));

    struct msghdr msg = {0};
    msg.msg_control    = control.buf;
    msg.msg_controllen = sizeof(control.buf);

    const ssize_t rd = recvmsg(fd, &msg, MSG_ERRQUEUE | MSG_DONTWAIT);
    if (rd < 0) {
        if (errno == EAGAIN || errno == EWOULDBLOCK) {
            return 0;
        }
        return getNegatedErrno();
    }

    if (out_tx_id) {
        (void)parseTxIDFromErrqueue(&msg, out_tx_id);
    }

    struct timespec tss[3] = {{0}};
    (void)parseTimestampingCmsg(&msg, tss);
    const int64_t sw_ns  = timespecToNanoseconds(&tss[0]); // software (system domain)
    const int64_t raw_ns = timespecToNanoseconds(&tss[2]); // raw HW (device domain)

    *out_sw_timestamp_usec = (CanardMicrosecond)(sw_ns / NANOSECONDS_PER_MICROSECOND);
    *out_raw_hw_timestamp_usec = (CanardMicrosecond)(raw_ns / NANOSECONDS_PER_MICROSECOND);

    int64_t chosen_ns = sw_ns;

    if (!chosen_ns) {
        struct timespec ts_fallback = {0};
        if (clock_gettime(CLOCK_REALTIME, &ts_fallback) == 0) {
            chosen_ns = timespecToNanoseconds(&ts_fallback);
        }
    }
    return poll_result;
}


int16_t socketcanFilter(const SocketCANFD fd, const size_t num_configs, const CanardFilter* const configs)
{
    if (configs == NULL)
    {
        return -EINVAL;
    }
    if (num_configs > CAN_RAW_FILTER_MAX)
    {
        return -EFBIG;
    }

    struct can_filter cfs[CAN_RAW_FILTER_MAX];
    for (size_t i = 0; i < num_configs; i++)
    {
        cfs[i].can_id   = (configs[i].extended_can_id & CAN_EFF_MASK) | CAN_EFF_FLAG;
        cfs[i].can_mask = (configs[i].extended_mask & CAN_EFF_MASK) | CAN_EFF_FLAG | CAN_RTR_FLAG;
    }

    const int ret =
        setsockopt(fd, SOL_CAN_RAW, CAN_RAW_FILTER, cfs, (socklen_t) (sizeof(struct can_filter) * num_configs));

    return (ret < 0) ? getNegatedErrno() : 0;
}
