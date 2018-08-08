#!/bin/bash

if [ -d "/opt/ros/melodic" ]; then
    echo "Found ROS Melodic";
    export ROS_SOURCE_BASH_FILE="/opt/ros/melodic/setup.bash";
elif [ -d "/opt/ros/kinetic" ]; then
    echo "Found ROS Kinetic";
    export ROS_SOURCE_BASH_FILE="/opt/ros/kinetic/setup.bash";
else 
    echo "Neither Melodic or Kinetic appear to be installed. Cannot source ROS dependencies";
    exit 1;
fi