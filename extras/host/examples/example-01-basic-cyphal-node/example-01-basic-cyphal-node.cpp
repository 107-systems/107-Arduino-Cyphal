/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020-2023 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-Cyphal/graphs/contributors.
 */

/**************************************************************************************
 * INCLUDES
 **************************************************************************************/

#include <cstdlib>

#include <SocketCAN.h>

/**************************************************************************************
 * MAIN
 **************************************************************************************/

int main(int argc, char ** argv)
{
  SocketCAN socket_can("can0", SocketCAN::Protocol::Classic);

  return EXIT_SUCCESS;
}
