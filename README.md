# Beginner_tutorial
ROS Beginner Tutorials

# Publisher Subscriber
A simple example of a ROS Publisher and Subscriber

# Contents
- include/ - header files
- src/ - source file as per Modern C++ format
- results/ - cpplint, cppcheck and rqt_console output

# Parameters
- publisher_rate: default = 10

# Service
- modify_Message: Modifies the message from the publisher and returns the new message

# Dependencies
- ROS Melodic
- CMake

### Steps to run:
```
mkdir -p catkin_ws/src
cd catkin_ws/src

git clone https://github.com/siddharthtelang/beginner__tutorials.git

cd ..
catkin build

source devel/setup.bash

roslaunch beginner__tutorials pub_sub.launch publisher_rate:=1

```
# ROS Service from command line
```
rosservice call /modify_Message "str1: 'Hello'"
```