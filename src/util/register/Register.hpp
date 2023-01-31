/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020-2023 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-Cyphal/graphs/contributors.
 */

#ifndef REGISTER_DERIVED_HPP_
#define REGISTER_DERIVED_HPP_

/**************************************************************************************
 * INCLUDES
 **************************************************************************************/

#include "RegisterBase.h"

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace impl
{

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

template<typename T>
class Register : public RegisterBase
{
public:
  Register(std::string const &name,
           Access const access,
           Persistent const is_persistent,
           T const & initial_val);


  inline T get() const { return _val; }
  void set(T const &val);


private:
  T _val;
};

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* impl */

/**************************************************************************************
 * TYPEDEF
 **************************************************************************************/

typedef impl::Register<uavcan::primitive::String_1_0>           RegisterString;
typedef impl::Register<uavcan::primitive::array::Bit_1_0>       RegisterBit;
typedef impl::Register<uavcan::primitive::array::Integer8_1_0>  RegisterInteger8;
typedef impl::Register<uavcan::primitive::array::Integer16_1_0> RegisterInteger16;
typedef impl::Register<uavcan::primitive::array::Integer32_1_0> RegisterInteger32;
typedef impl::Register<uavcan::primitive::array::Integer64_1_0> RegisterInteger64;
typedef impl::Register<uavcan::primitive::array::Natural8_1_0>  RegisterNatural8;
typedef impl::Register<uavcan::primitive::array::Natural16_1_0> RegisterNatural16;
typedef impl::Register<uavcan::primitive::array::Natural32_1_0> RegisterNatural32;
typedef impl::Register<uavcan::primitive::array::Natural64_1_0> RegisterNatural64;
typedef impl::Register<uavcan::primitive::array::Real16_1_0>    RegisterReal16;
typedef impl::Register<uavcan::primitive::array::Real32_1_0>    RegisterReal32;
typedef impl::Register<uavcan::primitive::array::Real64_1_0>    RegisterReal64;

/**************************************************************************************
 * TEMPLATE IMPLEMENTATION
 **************************************************************************************/

#include "Register.ipp"

#endif /* REGISTER_DERIVED_HPP_ */
