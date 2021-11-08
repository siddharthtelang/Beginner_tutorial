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
    std::string service_name;
    int rate;
    /**
     * @brief initialize the publisher
     * 
     */
    void init();

    void init_service();

    bool modify(beginner__tutorials::modify_Message::Request &req,
                       beginner__tutorials::modify_Message::Response &res);
};
