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
  initServiceClient();
}

Listener::~Listener() {
  delete nh;
}

void Listener::listenerCallback(const std_msgs::String::ConstPtr& msg) {
  ROS_INFO("ROS LISTENER HEARD: [%s]", msg->data.c_str());
  srv.request.str1 = msg->data;
  if (client.call(srv)) {
    ROS_INFO_STREAM("something" << srv.response.str2);
  }
}

void Listener::init() {
  subs = nh->subscribe("talker", 1000, &Listener::listenerCallback, this);
}

void Listener::startNode() {
  ros::spin();
}

void Listener::initServiceClient() {
  client = nh->serviceClient<beginner__tutorials::modify_Message>
          ("/modify_Message");
}
