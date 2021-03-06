#!/usr/bin/env python
###
# KINOVA (R) KORTEX (TM)
#
# Copyright (c) 2018 Kinova inc. All rights reserved.
#
# This software may be modified and distributed 
# under the terms of the BSD 3-Clause license.
#
# Refer to the LICENSE file for details.
#
###

import sys
import rospy
from kortex_device_manager.srv import *

def ReadAllDevices_client():
    rospy.wait_for_service('ReadAllDevices')
    try:
        function_ReadAllDevices = rospy.ServiceProxy('ReadAllDevices', ReadAllDevices)
        resp1 = function_ReadAllDevices()
        print(resp1)
    except rospy.ServiceException as e:
        print "Service call failed: %s"%e



if __name__ == "__main__":
    ReadAllDevices_client()