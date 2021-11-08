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
#include "beginner__tutorials/modify_Message.h"

class Listener {
 public:
    ros::NodeHandle *nh;
    ros::Subscriber subs;
    /**
     * @brief Construct a new Listener object
     * 
     * @param nh_  ROS handle
     */
    explicit Listener(ros::NodeHandle *nh_);
    /**
     * @brief Destroy the Listener object
     * 
     */
    ~Listener();
    /**
     * @brief start the listener node
     * 
     */
    void startNode();

 private:
    ros::ServiceClient client;
    beginner__tutorials::modify_Message srv;
    /**
     * @brief initialize the listener
     * 
     */
    void init();
    /**
     * @brief Listener callback
     * 
     * @param msg - message from subscriber
     */
    void listenerCallback(const std_msgs::String::ConstPtr& msg);
    void initServiceClient();
};

