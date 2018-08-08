#include <gtest/gtest.h>
#include "primary/primary_controller.h"

namespace altinners
{

namespace primary_controller
{
    
TEST(PrimaryControllerSuite, ThePoopTest)
{
    EXPECT_EQ(1, 1);
}

}

}

// Run all the tests that were declared with TEST()
int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc, argv);

  // Initialise ROS once GTest has set itself up
  ros::init(argc, argv, "PrimaryControllerIntegrationTests");

  return RUN_ALL_TESTS();
}
