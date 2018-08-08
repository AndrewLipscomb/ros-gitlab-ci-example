#include "primary/primary_controller.h"

namespace altinners
{

namespace primary_controller 
{

using namespace std;

PrimaryController::PrimaryController(ros::NodeHandle& nh)
{
    reset_srv_ = nh.advertiseService("reset", &PrimaryController::reset, this);

    status_pub_ = nh.advertise<std_msgs::String>("status", 10);

    secondary_integer_sub_ = nh.subscribe("secondary/integer", 10, &PrimaryController::secondary_integer_callback, this);
    secondary_double_sub_ = nh.subscribe("secondary/double", 10, &PrimaryController::secondary_double_callback, this);
}

bool PrimaryController::reset(std_srvs::Empty::Request& req, std_srvs::Empty::Response& resp)
{
    cout << "Reset was triggered" << endl;
    return true;
}

void PrimaryController::secondary_integer_callback(const std_msgs::Int64::ConstPtr& msg)
{
    cout << "Secondary has sent " << msg->data << endl;
}

void PrimaryController::secondary_double_callback(const std_msgs::Float64::ConstPtr& msg)
{
    cout << "Secondary has sent " << msg->data << endl;
}

}

}