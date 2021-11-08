/**
 * MIT License
 *
 * Copyright (c) 2021 Siddharth Telang
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
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
    /**
     * @brief initialize the service Client
     * 
     */
    void initServiceClient();
};

