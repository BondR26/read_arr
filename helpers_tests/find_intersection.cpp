#include "pch.h" // Include your precompiled header if needed

#include <tuple>
#include <vector>


// Define the test fixture class with parameterized tests
class FindIntersectionTest : public ::testing::TestWithParam<std::tuple<std::vector<int>, std::vector<int>, std::vector<int>>> {};

// Test case using the parameterized fixture
TEST_P(FindIntersectionTest, FindIntersectionTest)
{
    std::vector<int> input_1 = std::get<0>(GetParam());
    std::vector<int> input_2 = std::get<1>(GetParam());

    auto result = helpers::findIntersection<int>(input_1, input_2);

    std::vector<int> expected_res = std::get<2>(GetParam());

    EXPECT_EQ(result, expected_res);
}

// Define the parameter values: {first_arr, second_arr, expected_output}
INSTANTIATE_TEST_CASE_P(Default, FindIntersectionTest,
    ::testing::Values(
        std::make_tuple(std::vector<int>{3, 4, 5, 6, 7}, std::vector<int>{1, 2, 3, 4, 5}, std::vector<int>{3, 4, 5}),
        std::make_tuple(std::vector<int>{3, 4, 5, 1123}, std::vector<int>{1123, 1232112, 123, 4123, 52}, std::vector<int>{1123}),
        std::make_tuple(std::vector<int>{11, 22, 33, 44, 55}, std::vector<int>{11, 22, 33, 44, 55}, std::vector<int>{11, 22, 33, 44, 55})
    ));
