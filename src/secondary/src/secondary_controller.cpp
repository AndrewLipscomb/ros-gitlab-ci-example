#include "secondary/secondary_controller.h"

namespace altinners
{

namespace secondary_controller 
{

using namespace std;

SecondaryController::SecondaryController(ros::NodeHandle& nh)
{
    reset_srv_ = nh.advertiseService("reset", &SecondaryController::reset, this);

    status_pub_ = nh.advertise<std_msgs::String>("status", 10);

    secondary_integer_pub_ = nh.advertise<std_msgs::Int64>("secondary/integer", 10);
    secondary_double_pub_ = nh.advertise<std_msgs::Float64>("secondary/double", 10);
}

bool SecondaryController::reset(std_srvs::Empty::Request& req, std_srvs::Empty::Response& resp)
{
    cout << "Reset was triggered" << endl;
    return true;
}

}

}