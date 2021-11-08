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
  ROS_INFO_STREAM("ROS LISTENER HEARD: " << msg->data.c_str());
  srv.request.str1 = msg->data;
  if (client.call(srv)) {
    ROS_INFO_STREAM("Received response from service - " << srv.response.str2);
  } else {
    ROS_ERROR_STREAM("Failed to call service");
  }
}

void Listener::init() {
  subs = nh->subscribe("talker", 1000, &Listener::listenerCallback, this);
  if (subs.getNumPublishers() == 0)
    ROS_FATAL("Could not subscribe to publisher");
}

void Listener::startNode() {
  ros::spin();
}

void Listener::initServiceClient() {
  client = nh->serviceClient<beginner__tutorials::modify_Message>
          ("/modify_Message");
}
