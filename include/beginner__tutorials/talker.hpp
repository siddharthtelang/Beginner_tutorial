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
 * @file talker.hpp
 * @author Siddharth Telang (stelang@umd.edu)
 * @brief 
 * @version 0.1
 * @date 2021-11-01
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef INCLUDE_BEGINNER__TUTORIALS_TALKER_HPP_
#define INCLUDE_BEGINNER__TUTORIALS_TALKER_HPP_
#endif  // INCLUDE_BEGINNER__TUTORIALS_TALKER_HPP_

#include <tf/transform_broadcaster.h>
#include <string>
#include <sstream>
#include "ros/ros.h"
#include "std_msgs/String.h"
#include "beginner__tutorials/modify_Message.h"

class Talker {
 public:
    ros::NodeHandle *nh;
    /**
     * @brief Construct a new Talker object
     * 
     * @param nh_ handle
     */
    explicit Talker(ros::NodeHandle *nh_);
    /**
     * @brief Destroy the Talker object
     * 
     */
    ~Talker();
    /**
     * @brief Start the publisher
     * 
     */
    void startNode();

 private:
    std::string topic;
    ros::Publisher simple_publisher;
    ros::ServiceServer server;
    std::string service_name, parent_frame, child_frame;
    double x, y, z, roll, pitch, yaw;
    int rate;
    /**
     * @brief initialize the publisher
     * 
     */
    void init();
    /**
     * @brief Initialize the Service
     * 
     */
    void init_service();
    /**
     * @brief Initialize the parameters
     * 
     */
    void init_params();
    /**
     * @brief Service call functionality
     * 
     * @param req request from service
     * @param res response from service
     * @return true 
     * @return false 
     */
    bool modify(beginner__tutorials::modify_Message::Request &req, // NOLINT
                       beginner__tutorials::modify_Message::Response &res);  //NOLINT

    void broadcastTransform();
};
