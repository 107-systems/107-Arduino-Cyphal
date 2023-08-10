/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020-2023 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-Cyphal/graphs/contributors.
 */

#pragma once

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <memory>

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace cyphal
{

namespace impl
{

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

template <typename T>
class PublisherBase
{
public:
  PublisherBase() { }
  virtual ~PublisherBase() { }
  PublisherBase(PublisherBase const &) = delete;
  PublisherBase(PublisherBase &&) = delete;
  PublisherBase &operator=(PublisherBase const &) = delete;
  PublisherBase &operator=(PublisherBase &&) = delete;

  virtual bool publish(T const & msg) = 0;
};

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* impl */

/**************************************************************************************
 * TYPEDEF
 **************************************************************************************/

template <typename T>
using Publisher = std::shared_ptr<impl::PublisherBase<T>>;

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* cyphal */
