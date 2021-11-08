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
  init_service();
}

Talker::~Talker() {
  delete nh;
}

void Talker::init() {
  simple_publisher = nh->advertise<std_msgs::String>("talker", 1000);
  rate = 1;
}

void Talker::init_service() {
  service_name = "modify_Message";
  server = nh->advertiseService(service_name, &Talker::modify, this);
}

bool Talker::modify(beginner__tutorials::modify_Message::Request &req,
                   beginner__tutorials::modify_Message::Response &res) {
  res.str2 = req.str1 + " - Subscriber Called Service Successfully";
  return true;
}

void Talker::startNode() {
  ROS_DEBUG("Starting Talker node");
  int count {};
  ros::Rate loop_rate(rate);
  if (rate != 10) {
    ROS_WARN_STREAM("Loop rate has been modified from 10 Hz to"
                    << rate <<" Hz");
  }
  while (ros::ok()) {
    std_msgs::String msg;
    std::stringstream ss;
    ss << " Sending HELLO FROM PUBLISHER " << count++;
    msg.data = ss.str();
    ROS_INFO("%s", msg.data.c_str());
    simple_publisher.publish(msg);
    ros::spinOnce();
    loop_rate.sleep();
  }
}
