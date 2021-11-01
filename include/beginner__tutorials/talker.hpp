/**
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


#include <string>
#include <sstream>
#include "ros/ros.h"
#include "std_msgs/String.h"

class Talker {
 public:
    ros::NodeHandle *nh;
    explicit Talker(ros::NodeHandle *nh_);
    ~Talker();
    void startNode();
 private:
    std::string topic;
    ros::Publisher simple_publisher;
    int rate;
    void init();
};
