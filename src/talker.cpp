/**
 * @file talker.cpp
 * @author Siddharth Telang (stelang@umd.edu)
 * @brief 
 * @version 0.1
 * @date 2021-11-01
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "../include/beginner__tutorials/talker.hpp"

Talker::Talker(ros::NodeHandle *nh_) {
  nh = nh_;
  init();
}

Talker::~Talker() {
  delete nh;
}

void Talker::init() {
  simple_publisher = nh->advertise<std_msgs::String>("talker", 1000);
}

void Talker::startNode() {
  int count {};
  ros::Rate loop_rate(10);
  while (ros::ok()) {
    std_msgs::String msg;
    std::stringstream ss;
    ss << " HELLO FROM PUBLISHER " << count++;
    msg.data = ss.str();
    ROS_INFO("%s", msg.data.c_str());
    simple_publisher.publish(msg);
    ros::spinOnce();
    loop_rate.sleep();
  }
}
