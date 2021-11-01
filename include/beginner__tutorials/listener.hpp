/**
 * @file listener.hpp
 * @author Siddharth Telang (stelang@umd.edu)
 * @brief 
 * @version 0.1
 * @date 2021-11-01
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef INCLUDE_BEGINNER__TUTORIALS_LISTENER_HPP_
#define INCLUDE_BEGINNER__TUTORIALS_LISTENER_HPP_
#endif  // INCLUDE_BEGINNER__TUTORIALS_LISTENER_HPP_

#include <ros/ros.h>
#include <std_msgs/String.h>
#include <sstream>
#include <string>

class Listener {
 public:
    ros::NodeHandle *nh;
    ros::Subscriber subs;
    explicit Listener(ros::NodeHandle *nh_);
    ~Listener();
    void startNode();

 private:
    void init();
    void listenerCallback(const std_msgs::String::ConstPtr& msg);
};

