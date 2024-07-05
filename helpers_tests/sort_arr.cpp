#include "pch.h"


class SortArrayTest : public ::testing::TestWithParam<std::pair<std::vector<int>, std::vector<int>>>
{
    // Test fixture class for parameterized tests
};

// Define the parameter values: {input_string, expected_output}
INSTANTIATE_TEST_CASE_P(Default, SortArrayTest,
    ::testing::Values(
         std::make_pair(std::vector<int>{5, 2, 1, 3, 4}, std::vector<int>{1,2,3,4,5}),
         std::make_pair(std::vector<int>{1123, 1232112, 123, 4123, 52}, std::vector<int>{52, 123,1123, 4123, 1232112 }),
         std::make_pair(std::vector<int>{55, 11, 22, 33, 44}, std::vector<int>{11, 22, 33, 44, 55})
    ));

// Test case using the parameterized fixture
TEST_P(SortArrayTest, SortArrayTest)
{
    std::vector<int> input_string = GetParam().first;

    helpers::selectionSort<int>(input_string);

    std::vector<int> expected_output = GetParam().second;

    EXPECT_EQ(input_string, expected_output);
}