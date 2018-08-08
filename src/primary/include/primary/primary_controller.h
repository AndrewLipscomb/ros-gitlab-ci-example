#ifndef PRIMARY_CONTROLLER_
#define PRIMARY_CONTROLLER_

#include <vector>
#include <string>

#include "ros/ros.h"
#include "std_msgs/Int64.h"
#include "std_msgs/Float64.h"
#include "std_msgs/String.h"
#include "std_srvs/Empty.h"

namespace altinners
{

namespace primary_controller 
{

class PrimaryController
{
    public:
	    explicit PrimaryController(ros::NodeHandle& nh);

    protected:
        bool reset(std_srvs::Empty::Request& req, std_srvs::Empty::Response& resp);

        void secondary_integer_callback(const std_msgs::Int64::ConstPtr& msg);
        void secondary_double_callback(const std_msgs::Float64::ConstPtr& msg);

    private:
        ros::ServiceServer reset_srv_;					///< ROS Service to reset

        ros::Publisher status_pub_;				        //< Publishes a status

        ros::Subscriber secondary_integer_sub_;			///< Subscribes to an integer from secondary
        ros::Subscriber secondary_double_sub_;			///< Subscribes to a double from secondary

};

}

}

#endif //PRIMARY_CONTROLLER