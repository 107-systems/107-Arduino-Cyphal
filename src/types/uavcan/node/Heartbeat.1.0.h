/**
 * @brief   Arduino library for providing a convenient C++ interface for accessing UAVCAN.
 * @license MIT
 */

#ifndef ARDUINO_TRANSFER_UAVCAN_NODE_HEARTBEAT_1_0_H_
#define ARDUINO_TRANSFER_UAVCAN_NODE_HEARTBEAT_1_0_H_

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <stdlib.h>

#include <libcanard/canard.h>

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

class Heartbeat_1_0
{

public:

  enum class Health : uint8_t
  {
    NOMINAL  = 0,
    ADVISORY = 1,
    CAUTION  = 2,
    WARNING  = 3,
  };

  enum class Mode : uint8_t
  {
    OPERATIONAL      = 0,
    INITIALIZATION   = 1,
    MAINTENANCE      = 2,
    SOFTWARE_UPDATE  = 3,
    OFFLINE          = 7,
  };

  static constexpr CanardPortID PORT_ID = 32085;
  static constexpr size_t       MAX_PAYLOAD_SIZE = 7;

  Heartbeat_1_0(uint32_t const uptime, Health const health, Mode const mode, uint32_t const vssc);

  static Heartbeat_1_0 create(CanardTransfer const & transfer);


  size_t encode(uint8_t * payload) const;


  inline uint32_t uptime() const { return _uptime; }
  inline Health   health() const { return _health; }
  inline Mode     mode  () const { return _mode; }
  inline uint32_t vssc  () const { return _vssc; }

  inline void     uptime(uint32_t const uptime) { _uptime = uptime; }
  inline void     health(Health const health)   { _health = health; }
  inline void     mode  (Mode const mode)       { _mode = mode; }
  inline void     vssc  (uint32_t const vssc)   { _vssc = vssc; }


private:

  uint32_t _uptime;
  Health _health;
  Mode _mode;
  uint32_t _vssc;

};

#endif /* ARDUINO_TRANSFER_UAVCAN_NODE_HEARTBEAT_1_0_H_ */
