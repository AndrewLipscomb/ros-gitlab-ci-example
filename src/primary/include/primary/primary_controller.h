#ifndef PRIMARY_CONTROLLER_
#define PRIMARY_CONTROLLER_

#include <vector>
#include <string>

#include "ros/ros.h"
#include "std_msgs/Int64.h"
#include "std_msgs/Float64.h"
#include "std_msgs/String.h"
#include "std_srvs/Empty.h"

#include "nlohmann/json.hpp"

namespace altinners
{

namespace primary_controller 
{

/**
 * @brief The Primary Controller node for this example
 * 
 * Listens for an integer and a double from the system, and outputs a
 * status string which will be one of
 * 
 * - `NONE`
 *   when nothing has been sent
 * - `EVEN`
 *   when the last message was an even integer
 * - `ODD`
 *   when the last message was an odd integer
 * - `FLOAT`
 *   when the last message was a double
 * 
 * It also has a reset service which clears the status back to `NONE`
 * 
 */
class PrimaryController
{
    public:
        /**
         * @brief Construct a new Primary Controller object
         * 
         * @param nh A node handle
         */
	    explicit PrimaryController(ros::NodeHandle& nh);

        /**
         * @brief Get the last int object
         * 
         * @return int64_t 
         */
        int64_t get_last_int() const;

        /**
         * @brief Get the last double object
         * 
         * @return double 
         */
        double get_last_double() const;

    protected:
        /**
         * @brief Resets the status to `NONE`
         * 
         * @return true Always
         * @return false Never
         */
        bool reset(std_srvs::Empty::Request& , std_srvs::Empty::Response& );

        /**
         * @brief Callback for the integer topic
         * 
         * @param msg An integer message
         */
        void secondary_integer_callback(const std_msgs::Int64::ConstPtr& msg);

        /**
         * @brief Callback for the double topic
         * 
         * @param msg A double message
         */
        void secondary_double_callback(const std_msgs::Float64::ConstPtr& msg);

    private:
        ros::ServiceServer reset_srv_;					//< ROS Service to reset

        ros::Publisher status_pub_;				        //< Publishes a status

        ros::Subscriber secondary_integer_sub_;			//< Subscribes to an integer from secondary
        int64_t last_int_ = 0;

        ros::Subscriber secondary_double_sub_;			//< Subscribes to a double from secondary
        double last_double_ = 0.0;

};

}

}

#endif //PRIMARY_CONTROLLER