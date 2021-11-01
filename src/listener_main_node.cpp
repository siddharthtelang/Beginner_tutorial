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

#include "beginner__tutorials/listener.hpp"

int main(int argc, char **argv) {
    ros::init(argc, argv, "listener");
    ros::NodeHandle *handle = new ros::NodeHandle();
    Listener listener(handle);
    listener.startNode();
    delete handle;
    return 1;
}
