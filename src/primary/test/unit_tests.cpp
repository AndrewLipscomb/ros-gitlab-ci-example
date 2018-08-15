#include <gtest/gtest.h>
#include "primary/primary_controller.h"

namespace altinners
{

namespace primary_controller
{
    
TEST(PrimaryControllerSuite, TrivialTest)
{
    EXPECT_EQ(1, 1);
}

TEST(PrimaryControllerSuite, IntegerTypeTest)
{
    ros::NodeHandle private_nh("/");
    PrimaryController primary(private_nh);
    EXPECT_EQ(typeid(int64_t), typeid(primary.get_last_int()));
}

TEST(PrimaryControllerSuite, DoubleTypeTest)
{
    ros::NodeHandle private_nh("/");
    PrimaryController primary(private_nh);
    EXPECT_EQ(typeid(double), typeid(primary.get_last_double()));
}

// TEST(PrimaryControllerSuite, FailingTest)
// {
//     ros::NodeHandle private_nh("/");
//     PrimaryController primary(private_nh);
//     EXPECT_EQ(typeid(double), typeid(primary.get_last_int()));
// }

}

}

// Run all the tests that were declared with TEST()
int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc, argv);

  // Initialise ROS once GTest has set itself up
  ros::init(argc, argv, "PrimaryControllerUnitTests");

  return RUN_ALL_TESTS();
}
