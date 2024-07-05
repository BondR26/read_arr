#include "pch.h"

// Main function to run all tests
int main(int argc, char** argv) 
{
    ::testing::InitGoogleTest(&argc, argv);

    // Set the filter to run only the SplitStringTest.SplitStringTest test case
    //::testing::GTEST_FLAG(filter) = "SplitStringTest.SplitStringTest";

    return RUN_ALL_TESTS();
}