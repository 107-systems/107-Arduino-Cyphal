/**
 * @brief   Arduino library for controlling the Zubax Orel 20.
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

  typedef struct 
  {
    uint32_t uptime;
    Health health;
    Mode mode;
    uint32_t vssc;
  } Data;

  Heartbeat_1_0(CanardTransfer const & transfer)
  {
    _data.mode   = static_cast<Mode>  (canardDSDLGetU8 (reinterpret_cast<uint8_t const *>(transfer.payload), transfer.payload_size, 34,  3));
    _data.uptime =                     canardDSDLGetU32(reinterpret_cast<uint8_t const *>(transfer.payload), transfer.payload_size,  0, 32);
    _data.vssc   =                     canardDSDLGetU32(reinterpret_cast<uint8_t const *>(transfer.payload), transfer.payload_size, 37, 19);
    _data.health = static_cast<Health>(canardDSDLGetU8 (reinterpret_cast<uint8_t const *>(transfer.payload), transfer.payload_size, 32,  2));
  }


  inline uint32_t uptime() const { return _data.uptime; }
  inline Health   health() const { return _data.health; }
  inline Mode     mode  () const { return _data.mode; }
  inline uint32_t vssc  () const { return _data.vssc; }


private:
  
  Data _data;

};

/**************************************************************************************
 * TYPEDEF
 **************************************************************************************/

typedef std::function<void(CanardNodeID const node_id, Heartbeat_1_0 const &)> OnHeartbeat_1_0_ReceivedFunc;

#endif /* ARDUINO_TRANSFER_UAVCAN_NODE_HEARTBEAT_1_0_H_ */
