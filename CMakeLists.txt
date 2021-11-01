cmake_minimum_required(VERSION 3.0.2)
project(beginner__tutorials)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
)

catkin_package(
 INCLUDE_DIRS include
)

include_directories(
include
  ${catkin_INCLUDE_DIRS}
)

add_executable(talker_node src/talker.cpp src/talker_main_node.cpp)
add_executable(listener_node src/listener.cpp src/listener_main_node.cpp)


target_link_libraries(talker_node
  ${catkin_LIBRARIES}
)
target_link_libraries(listener_node
  ${catkin_LIBRARIES}
)
