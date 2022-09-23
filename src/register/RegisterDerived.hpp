/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-Cyphal/graphs/contributors.
 */

#ifndef REGISTER_READ_ONLY_H_
#define REGISTER_READ_ONLY_H_

/**************************************************************************************
 * INCLUDES
 **************************************************************************************/

#include "RegisterBase.h"
#include "types/Access.h"
#include "util/register_util.hpp"

extern unsigned long micros(void);

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

template <typename T>
class RegisterDerived : public RegisterBase
{
public:
  typedef std::function<void(RegisterDerived<T> const &)> OnRegisterValueChangeFunc;

  RegisterDerived(char const * name,
                  Register::Access const access,
                  T const & initial_val,
                  OnRegisterValueChangeFunc func);

  inline T get() const { return _val; }
  void set(uavcan_register_Value_1_0 const & val);
  uavcan::_register::Access_1_0::Response<> toAccessResponse();


private:
  T _val;
  Register::Access const _access;
  OnRegisterValueChangeFunc _func;
};

/**************************************************************************************
 * TYPEDEF
 **************************************************************************************/

typedef RegisterDerived<std::string> RegisterString;
typedef RegisterDerived<bool>        RegisterBit;
typedef RegisterDerived<int8_t>      RegisterInteger8;
typedef RegisterDerived<int16_t>     RegisterInteger16;
typedef RegisterDerived<int32_t>     RegisterInteger32;
typedef RegisterDerived<int64_t>     RegisterInteger64;
typedef RegisterDerived<uint8_t>     RegisterNatural8;
typedef RegisterDerived<uint16_t>    RegisterNatural16;
typedef RegisterDerived<uint32_t>    RegisterNatural32;
typedef RegisterDerived<uint64_t>    RegisterNatural64;
typedef RegisterDerived<float>       RegisterReal32;
typedef RegisterDerived<double>      RegisterReal64;

/**************************************************************************************
 * TEMPLATE IMPLEMENTATION
 **************************************************************************************/

#include "RegisterDerived.ipp"

#endif /* REGISTER_READ_ONLY_H_ */
