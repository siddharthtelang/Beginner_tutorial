# Beginner_tutorial
ROS Beginner Tutorials

# Publisher Subscriber
A simple example of a ROS Publisher and Subscriber

# Contents
- include/ - header files
- src/ - source file as per Modern C++ format
- results/ - cpplint and cppcheck outputs

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

roscore
rosrun beginner__tutorials talker_node
rosrun beginner__tutorials listener_node

```
