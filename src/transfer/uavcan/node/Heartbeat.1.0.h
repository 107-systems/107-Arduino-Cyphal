/**
 * @brief   Arduino library for providing a convenient C++ interface for accessing UAVCAN.
 * @license MIT
 */

#ifndef ARDUINO_TRANSFER_UAVCAN_NODE_HEARTBEAT_1_0_H_
#define ARDUINO_TRANSFER_UAVCAN_NODE_HEARTBEAT_1_0_H_

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#undef max
#undef min
#include <functional>

#include <libcanard/canard.h>
#include <libcanard/canard_dsdl.h>

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


  Heartbeat_1_0(uint32_t const uptime, Health const health, Mode const mode, uint32_t const vssc);


  static Heartbeat_1_0 create(CanardTransfer const & transfer);


  inline uint32_t uptime() const { return _uptime; }
  inline Health   health() const { return _health; }
  inline Mode     mode  () const { return _mode; }
  inline uint32_t vssc  () const { return _vssc; }


private:

  uint32_t _uptime;
  Health _health;
  Mode _mode;
  uint32_t _vssc;

};

/**************************************************************************************
 * TYPEDEF
 **************************************************************************************/

typedef std::function<void(CanardNodeID const node_id, Heartbeat_1_0 const &)> OnHeartbeat_1_0_ReceivedFunc;

#endif /* ARDUINO_TRANSFER_UAVCAN_NODE_HEARTBEAT_1_0_H_ */
