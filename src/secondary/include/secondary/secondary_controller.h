#ifndef SECONDARY_CONTROLLER_
#define SECONDARY_CONTROLLER_

#include <vector>
#include <string>

#include "ros/ros.h"
#include "std_msgs/Int64.h"
#include "std_msgs/Float64.h"
#include "std_msgs/String.h"
#include "std_srvs/Empty.h"
// #include "secondary/custom_message.h"

namespace altinners
{

namespace secondary_controller 
{

class SecondaryController
{
    public:
        /**
         * @brief Construct a new Secondary Controller object
         * 
         * @param nh A node handle
         */
	    explicit SecondaryController(ros::NodeHandle& nh);

    protected:
        bool reset(std_srvs::Empty::Request& req, std_srvs::Empty::Response& resp);

    private:
        ros::ServiceServer reset_srv_;					//< ROS Service to reset

        ros::Publisher status_pub_;				        //< Publishes a status

        ros::Publisher secondary_integer_pub_;			//< Publishes an integer
        ros::Publisher secondary_double_pub_;			//< Publishes a double

};

}

}

#endif //SECONDARY_CONTROLLER