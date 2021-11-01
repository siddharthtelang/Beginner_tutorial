/**
 * @file listener_main_node.cpp
 * @author Siddharth Telang (stelang@umd.edu)
 * @brief 
 * @version 0.1
 * @date 2021-11-01
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "beginner__tutorials/talker.hpp"

int main(int argc, char **argv) {
    ros::init(argc, argv, "talker");
    ros::NodeHandle *handle = new ros::NodeHandle();
    Talker talker(handle);
    talker.startNode();
    delete handle;
    return 0;
}
