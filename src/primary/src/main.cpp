#include <ros/ros.h>
#include "primary/primary_controller.h"

int main(int argc, char** argv)
{
  ros::init(argc, argv, "primary");
  ros::NodeHandle private_nh("/");
  
  using namespace altinners::primary_controller;
  PrimaryController primary(private_nh);

  ros::spin();

  return 0;
}