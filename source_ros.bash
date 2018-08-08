#!/bin/bash

if [ -d "/opt/ros/melodic" ]; then
    echo "Sourcing ROS Melodic";
    source /opt/ros/melodic/setup.bash;
elif [ -d "/opt/ros/kinetic" ]; then
    echo "Sourcing ROS Kinetic";
    source /opt/ros/kinetic/setup.bash;
else 
    echo "Neither Melodic or Kinetic appear to be installed. Cannot source ROS dependencies";
    exit 1;
fi