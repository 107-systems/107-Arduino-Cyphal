/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-Cyphal/graphs/contributors.
 */

#ifndef REGISTER_H_
#define REGISTER_H_

/**************************************************************************************
 * INCLUDES
 **************************************************************************************/

#include <107-Arduino-Cyphal.h>

/**************************************************************************************
 * DEFINES
 **************************************************************************************/

/**************************************************************************************
 * TYPEDEF
 **************************************************************************************/

/**************************************************************************************
 * CONSTANTS
 **************************************************************************************/

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

class RegisterBase
{
public:
  RegisterBase(char const * name)
  {
    _name.name.count = std::min(strlen(name), uavcan_register_Name_1_0_name_ARRAY_CAPACITY_);
    memcpy(_name.name.elements, name, _name.name.count);
  }
  virtual ~RegisterBase() { }

  uavcan::_register::List_1_0::Response<> toListResponse() const
  {
    uavcan::_register::List_1_0::Response<> rsp;
    memcpy(&rsp.data.name.name.elements, _name.name.elements, _name.name.count);
    rsp.data.name.name.count = _name.name.count;
    return rsp;
  }

  virtual uavcan::_register::Access_1_0::Response<> toAccessResponse()
  {
    uavcan::_register::Access_1_0::Response<> rsp;
    return rsp;
  }

  bool operator == (uavcan_register_Name_1_0 const & reg_name)
  {
    if (reg_name.name.count != _name.name.count)
      return false;
    else
        return (strncmp(reinterpret_cast<const char *>(_name.name.elements),
                        reinterpret_cast<const char *>(reg_name.name.elements),
                        reg_name.name.count) == 0);
  }

private:
  uavcan_register_Name_1_0 _name;
};

template <typename T> uavcan_register_Value_1_0 toRegisterValue(T const & val);

template<> inline uavcan_register_Value_1_0 toRegisterValue<uint8_t>(uint8_t const & val)
{
  uavcan_register_Value_1_0 reg_val;
  reg_val.natural8.value.elements[0] = val;
  reg_val.natural8.value.count = 1;
  uavcan_register_Value_1_0_select_natural8_(&reg_val);
  return reg_val;
}

template<> inline uavcan_register_Value_1_0 toRegisterValue<std::string>(std::string const & val)
{
  uavcan_register_Value_1_0 reg_val;
  reg_val._string.value.count = std::min(val.length(), uavcan_register_Name_1_0_name_ARRAY_CAPACITY_);
  memcpy(reg_val._string.value.elements, val.c_str(), reg_val._string.value.count);
  uavcan_register_Value_1_0_select_string_(&reg_val);
  return reg_val;
}

template <typename T> T fromRegisterValue(uavcan_register_Value_1_0 const & val);

template<> inline uint8_t fromRegisterValue<uint8_t>(uavcan_register_Value_1_0 const & val)
{
  return val.natural8.value.elements[0];
}

template<> inline std::string fromRegisterValue<std::string>(uavcan_register_Value_1_0 const & val)
{
  char str[uavcan_primitive_String_1_0_value_ARRAY_CAPACITY_] = {0};
  memcpy(str, val._string.value.elements, val._string.value.count);
  str[val._string.value.count + 1] = '\0';
  return std::string(str);
}

template <typename T>
class RegisterReadOnly : RegisterBase
{
public:

  RegisterReadOnly(char const * name,
                   T const & initial_val)
  : RegisterBase{name}
  , _val{initial_val}
  { }
  virtual ~RegisterReadOnly() { }

  inline T get() const { return _val; }

  virtual uavcan::_register::Access_1_0::Response<> toAccessResponse()
  {
    uavcan::_register::Access_1_0::Response<> rsp;

    rsp.data.value = toRegisterValue(_val);
    rsp.data.timestamp.microsecond = micros();
    rsp.data._mutable = false;
    rsp.data.persistent = false;

    return rsp;
  }

protected:
  inline void set(T const & val) { _val = val; }

private:
  T _val;
};

template<typename T>
class RegisterReadWrite : public RegisterReadOnly<T>
{
public:
  typedef std::function<void(RegisterReadWrite<T> const &)> OnRegisterValueChangeFunc;

  RegisterReadWrite(char const * name,
                    T const & initial_val,
                    OnRegisterValueChangeFunc func)
  : RegisterReadOnly<T>{name, initial_val}
  , _func{func}
  { }
  virtual ~RegisterReadWrite() { }

  virtual uavcan::_register::Access_1_0::Response<> toAccessResponse()
  {
    uavcan::_register::Access_1_0::Response<> rsp = RegisterReadOnly<T>::toAccessResponse();
    rsp.data._mutable = true;
    return rsp;
  }

  inline void set(uavcan_register_Value_1_0 const & val)
  {
    RegisterReadOnly<T>::set(fromRegisterValue<T>(val));
    if (_func)
      _func(*this);
  }

private:
  OnRegisterValueChangeFunc _func;
};

static RegisterReadWrite<uint8_t>     reg_rw_uavcan_node_id         ("uavcan.node.id", 42, nullptr);
static RegisterReadOnly <std::string> reg_ro_uavcan_node_description("uavcan.node.description", "OpenCyphal-ToF-Distance-Sensor-Node");
static RegisterBase                   reg_last                      ("");

static RegisterBase * REGISTER_LIST_ARRAY[] =
{
  reinterpret_cast<RegisterBase *>(&reg_rw_uavcan_node_id),
  reinterpret_cast<RegisterBase *>(&reg_ro_uavcan_node_description),
  reinterpret_cast<RegisterBase *>(&reg_last)
};
static size_t const REGISTER_LIST_ARRAY_SIZE = sizeof(REGISTER_LIST_ARRAY) / sizeof(REGISTER_LIST_ARRAY[0]);


#endif /* REGISTER_H_ */
