/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-Cyphal/graphs/contributors.
 */

/**************************************************************************************
 * EXTERN DECLARATION
 **************************************************************************************/

extern "C" unsigned long micros(void);

/**************************************************************************************
 * CTOR/DTOR
 **************************************************************************************/

template <typename T>
RegisterDerived<T>::RegisterDerived(char const * name,
                                    Register::Access const access,
                                    Register::Persistent const is_persistent,
                                    T const & initial_val,
                                    OnWriteRequestFunc on_write_request_func,
                                    OnReadRequestFunc on_read_request_func)
: RegisterBase{name,
               Register::toTypeTag(initial_val),
               (access == Register::Access::ReadOnly),
               (is_persistent == Register::Persistent::Yes)}
, _val{initial_val}
, _on_write_request_func{on_write_request_func}
, _on_read_request_func{on_read_request_func}
{ }
