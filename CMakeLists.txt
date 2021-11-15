cmake_minimum_required(VERSION 3.0.2)
project(beginner__tutorials)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  message_generation
  tf
)
add_service_files(
  FILES
  modify_Message.srv
)
generate_messages(
  DEPENDENCIES
  std_msgs
)

catkin_package(
 INCLUDE_DIRS include
)
catkin_package(
  CATKIN_DEPENDS
  message_runtime
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
add_dependencies(talker_node beginner__tutorials_gencpp)
add_dependencies(listener_node beginner__tutorials_gencpp)

if (CATKIN_ENABLE_TESTING)
  find_package(rostest REQUIRED)
  add_rostest_gtest(test_tf test/test_broadcaster.test test/tf_broadcaster_test.cpp)
  target_link_libraries(test_tf ${catkin_LIBRARIES})
endif()