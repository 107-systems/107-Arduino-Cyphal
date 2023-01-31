/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020-2023 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-Cyphal/graphs/contributors.
 */

/**************************************************************************************
 * EXTERN DECLARATION
 **************************************************************************************/

extern "C" unsigned long micros(void);

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace impl
{

/**************************************************************************************
 * CTOR/DTOR
 **************************************************************************************/

template<typename T>
Register<T>::Register(std::string const & name,
                      Access const access,
                      Persistent const is_persistent,
                      T const & initial_val)
: RegisterBase{name, access, is_persistent}
, _val{initial_val}
{ }

/**************************************************************************************
 * PUBLIC MEMBER FUNCTIONS
 **************************************************************************************/

template<typename T>
void Register<T>::set(T const &val)
{
  _val = val;
  uavcan::time::SynchronizedTimestamp_1_0 ts;
  ts.microsecond = micros();
  setTimestamp(ts);
}

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* impl */
