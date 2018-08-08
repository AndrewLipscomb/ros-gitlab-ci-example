#include <ros/ros.h>
#include "secondary/secondary_controller.h"

int main(int argc, char** argv)
{
  ros::init(argc, argv, "secondary");
  ros::NodeHandle private_nh("/");
  
  using namespace altinners::secondary_controller;
  SecondaryController secondary(private_nh);

  ros::spin();

  return 0;
}