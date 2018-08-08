#include <gtest/gtest.h>
#include "primary/primary_controller.h"

namespace altinners
{

namespace primary_controller
{
    
TEST(PrimaryControllerSuite, AnIntegrationTest)
{
    EXPECT_EQ(1, 1);
}

TEST(PrimaryControllerSuite, ABadTest)
{
    EXPECT_EQ(1, 0);
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
