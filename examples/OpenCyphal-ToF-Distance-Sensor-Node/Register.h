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
  RegisterBase(std::string const & name)
  : _name{name}
  { }

  void toListResponse(uavcan_register_List_Response_1_0 * rsp_ptr)
  {
    size_t const bytes_to_copy = std::min(_name.size(), uavcan_register_Name_1_0_name_ARRAY_CAPACITY_);
    memcpy(&(rsp_ptr->name.name.elements), _name.c_str(), bytes_to_copy);
    rsp_ptr->name.name.count = bytes_to_copy;
  }

  bool operator == (uavcan_register_Name_1_0 const & reg_name)
  {
    return (strncmp(_name.c_str(), reinterpret_cast<const char *>(reg_name.name.elements), reg_name.name.count) == 0);
  }

private:
  std::string const _name;
};

template <typename T>
class RegisterReadOnly : RegisterBase
{
public:

  RegisterReadOnly(std::string const & name,
                   T const & initial_val)
  : RegisterBase{name}
  , _val{initial_val}
  { }

  inline T get() const { return _val; }

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

  RegisterReadWrite(std::string const & name,
                    T const & initial_val,
                    OnRegisterValueChangeFunc func)
  : RegisterReadOnly<T>{name, initial_val}
  , _func{func}
  { }

  inline void set(T const & val)
  {
    RegisterReadOnly<T>::set(val);
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
