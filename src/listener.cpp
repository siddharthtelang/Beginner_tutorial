/**
 * @file listener.cpp
 * @author Siddharth Telang (stelang@umd.edu)
 * @brief 
 * @version 0.1
 * @date 2021-11-01
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include"beginner__tutorials/listener.hpp"

Listener::Listener(ros::NodeHandle *nh_) {
  nh = nh_;
  init();
}

Listener::~Listener() {
  delete nh;
}

void Listener::listenerCallback(const std_msgs::String::ConstPtr& msg) {
  ROS_INFO("ROS LISTENER HEARD: [%s]", msg->data.c_str());
}

void Listener::init() {
  subs = nh->subscribe("talker", 1000, &Listener::listenerCallback, this);
}

void Listener::startNode() {
  ros::spin();
}
