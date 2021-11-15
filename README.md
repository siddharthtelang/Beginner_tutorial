# Beginner_tutorial
ROS Beginner Tutorials

# Publisher Subscriber
A simple example of a ROS Publisher, Subscriber, Services, Client and Launch files

# Client Server
A simple example of Client Server

# TF Broadcasting and Listerner
Example to show how to broadcast tf and listen to it

# Contents
- include/ - header files
- src/ - source file as per Modern C++ format
- results/ - cpplint, cppcheck and rqt_console output
- test/ - ros test files

# Parameters
- publisher_rate: default = 10
- x,y,z, roll, pitch, yaw
- parent_frame, child_frame
- record_rosbag, rosbag_directory

# Service
- modify_Message: Modifies the message from the publisher and returns the new message

### Steps to run for publisher/subscriber:
```
mkdir -p catkin_ws/src
cd catkin_ws/src

git clone https://github.com/siddharthtelang/beginner__tutorials.git

cd ..
catkin build

source devel/setup.bash

roslaunch beginner__tutorials pub_sub.launch publisher_rate:=1
```

# Without launch file
```
roscore
rosrun beginner__tutorials talker_node
rosrun beginner__tutorials lister_node
```

# ROS Service from command line
```
rosservice call /modify_Message "str1: 'Hello'"
```

# Checking the TF
### Verifying the frames - frames.pdf
```
roslaunch beginner__tutorials pub_sub.launch
rosrun tf view_frames
```
### Checking the tf values
```
roslaunch beginner__tutorials pub_sub.launch
rosrun tf tf_echo world talk
```
### Passing values from command line
roslaunch beginner__tutorials pub_sub.launch x:=2 y:=3 z:=5 roll:=3.14 pitch:=0 yaw:=1.57

# ROS Test
## Compiling and running
```
catkin build
catkin build beginner__tutorials --catkin-make-args tests
rostest beginner__tutorials test_broadcaster.test
```

# ROS Bag
## Record manually
```
cd <directory>
roslaunch beginner__tutorials pub_sub.launch
rosbag record -O record_bag.bag -a --duration 15
```

## Record through launch file
```
roslaunch beginner__tutorials pub_sub.launch record_rosbag:=true rosbag_directory:=< your directory>
```

## Playing the rosbag
```
roscore
rosbag play <generated_file>
```

## Playing the stored rosbag
```
roscore
rosbag play results/rosbag.bag
```