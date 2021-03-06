<!-- 
* KINOVA (R) KORTEX (TM)
*
* Copyright (c) 2018 Kinova inc. All rights reserved.
*
* This software may be modified and distributed
* under the terms of the BSD 3-Clause license.
*
* Refer to the LICENSE file for details.
*
* -->

# Kortex Vision Config Module

## Overview
This package implements a ROS node that allows direct communication with a Gen3 Vision module. Direct communication means that either the computer running the node has an Ethernet cable directly connected to a Vision module or that it is connected to a robot using the device routing system. Use this package if you want to:

* Change a configuration setting on the Vision module.
* Get information about the configuration settings of the Vision module.

### License

The source code is released under a [BSD 3-Clause license](../LICENSE).

**Author: Kinova inc.<br />
Affiliation: [Kinova inc.](https://www.kinovarobotics.com/)<br />
Maintainer: Kinova inc. support@kinovarobotics.com**

This package has been tested under ROS Kinetic and Ubuntu 16.04.

## Installation

### Building from Source

#### Dependencies

- [ROS (Robot Operating System)](http://wiki.ros.org) robotics middleware
- [protobuf](https://developers.google.com/protocol-buffers/)

```cpp
git clone https://github.com/protocolbuffers/protobuf --branch 3.5.1.1   (you must use this specific version)
```
Follow these [instructions](https://github.com/protocolbuffers/protobuf/blob/master/src/README.md) to build and install protobuf and its compiler.

#### Building

To build from source, clone the latest version from this repository into your catkin workspace and compile the package using

        cd catkin_workspace/src
        git clone https://github.com/Kinovarobotics/ros_kortex.git
        cd ../
        sudo ./src/ros_kortex/build.sh

## Usage

<code>rosrun kortex\_vision\_config\_driver kortex\_vision\_config\_driver 192.168.1.10</code>

In the command above, you would be running the kortex\_vision\_config\_driver node on a Gen3 robot with IP address 192.168.1.10. 

## Nodes

### Published Topics

* **`/KortexError`**
    <p>Every Kortex error will be published here. </p>
    
    | Type | Name | Description |
    |:---:|:---:|:---:|
    | uint32 | code | Error code, see enum in the ErrorCodes class. |
    | uint32 | subcode | Sub error code, see enum in the ErrorCodes class. |
    | string | description | Error details |

### Services
Most of the services supported by this node are generated from the [ C++ Kortex API](https://github.com/Kinovarobotics/kortex). You can find the documentation [here](https://github.com/Kinovarobotics/kortex/blob/master/api_cpp/doc/markdown/index.md).

Example:
If you want to call the ROS service **`GetActuatorCount`** generated by the C++ method [GetActuatorCount](https://github.com/Kinovarobotics/kortex/blob/master/api_cpp/doc/markdown/references/summary_VisionConfig.md), you would initialize your service as follows:

    ros::ServiceClient client_GetSensorSettings = n.serviceClient<kortex_driver::GetSensorSettings>("GetSensorSettings");

#### Non generated
* **`SetApiOptions`**
    <p>Modifies the Kortex API options. Once this service is called, the options set will affect every future call to the node.</p>

* **`SetDeviceID`**
    <p>Modifies the target device (device routing feature) of the node. The default value is 0.</p>

### Messages
Most of the messages supported by this node are generated from the [C++ Kortex API](https://github.com/Kinovarobotics/kortex). You can find the documentation [here](https://github.com/Kinovarobotics/kortex/blob/master/api_cpp/doc/markdown/index.md).

#### Non generated
* **`ApiOptions`**
    <p>Represents all the Kortex API options.</p>

* **`KortexError`**
    <p>Represents a Kortex API error.</p>

### Protos files
The **protos** directory contains the protobuf files from where the MSG, SRV and source files are generated. The content of this folder should not be modified.

### Template files
The **templates** directory contains all the JINJA2 files needed by the protoc generator. For more details on the generation process, see the **Generation** section.

| File | Description |
|:---:|:---:|
| main.jinja2 | Used to generate src/main.cpp |
| NodeServices.cpp.jinja2 | Used to generate src/node.cpp |
| NodeServices.h.jinja2 | Used to generate src/node.h |
| proto_converterCPP.jinja2 | Used to generate every src/*_proto\_converter.cpp file |
| proto_converterHeader.jinja2 | Used to generate every src/*_proto\_converter.h file |
| ros_converterCPP.jinja2 | Used to generate every src/*_ros\_converter.cpp file |
| ros_converterHeader.jinja2 | Used to generate every src/*_proto\_converter.h file |
| ros_enum.jinja2 | Used to generate every msg/*.msg file that represents a protobuf enum |
| ros_message.jinja2 | Used to generate every msg/*.msg file that represents a protobuf message |
| ros_oneof.jinja2 | Used to generate every msg/*.msg file that represents a protobuf oneof |
| ros_service.jinja2 | Used to generate every msg/*.msg file that represents a protobuf RPC |

## Generation
<p>
The generation process is based on a custom protobuf plugin. Basically, most of the generation process is in the RosGeneration.py file located in the package root directory. Before launching the generation make sure you have the Python JINJA2 module installed.
</p>

To launch the generation of this package:

1. Open a terminal window.
1. Browse to the package root directory [YOUR\_ROS\_WORKSPACE]/src/ros\_kortex/kortex\_vision\_config\_driver/
1. Ensure that the file kortex\_vision\_config\_driver.sh can be executed. If not then <code>chmod +x kortex\_vision\_config\_driver.sh</code>
1. Run the command: <code>protoc --plugin=protoc-gen-custom=kortex\_vision\_config\_driver.sh -I./protos/ --custom_out=./build ./protos/\*.prot</code>
1. The result of the generation should be in the following folders:
    * /src
    * /msg
    * /srv

