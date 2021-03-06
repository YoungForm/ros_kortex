/*
* KINOVA (R) KORTEX (TM)
*
* Copyright (c) 2018 Kinova inc. All rights reserved.
*
* This software may be modified and distributed under the
* terms of the BSD 3-Clause license.
*
* Refer to the LICENSE file for details.
*
*/

/*
 * This file has been auto-generated and should not be modified.
 */
 
#ifndef _KORTEX_CommonROS_CONVERTER_H_
#define _KORTEX_CommonROS_CONVERTER_H_

#include "ros/ros.h"

#include <string>
#include <iostream>
#include <cstdio>
#include <iostream>
#include <chrono>

#include <Frame.pb.h>
#include <Session.pb.h>
#include <Common.pb.h>

#include <KDetailedException.h>
#include <HeaderInfo.h>

#include <TransportClientUdp.h>
#include <RouterClient.h>

#include <BaseCyclicClientRpc.h>
#include <BaseClientRpc.h>
#include <SessionClientRpc.h>
#include <SessionManager.h>

#include "kortex_driver/DeviceHandle.h"
#include "kortex_driver/Empty.h"
#include "kortex_driver/NotificationOptions.h"
#include "kortex_driver/SafetyHandle.h"
#include "kortex_driver/NotificationHandle.h"
#include "kortex_driver/SafetyNotification.h"
#include "kortex_driver/Timestamp.h"
#include "kortex_driver/UserProfileHandle.h"
#include "kortex_driver/Connection.h"


using namespace Kinova::Api::Common;

int ToRosData(DeviceHandle input, kortex_driver::DeviceHandle &output);
int ToRosData(Empty input, kortex_driver::Empty &output);
int ToRosData(NotificationOptions input, kortex_driver::NotificationOptions &output);
int ToRosData(SafetyHandle input, kortex_driver::SafetyHandle &output);
int ToRosData(NotificationHandle input, kortex_driver::NotificationHandle &output);
int ToRosData(SafetyNotification input, kortex_driver::SafetyNotification &output);
int ToRosData(Timestamp input, kortex_driver::Timestamp &output);
int ToRosData(UserProfileHandle input, kortex_driver::UserProfileHandle &output);
int ToRosData(Connection input, kortex_driver::Connection &output);

#endif