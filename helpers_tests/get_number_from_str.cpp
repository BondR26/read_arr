#include "pch.h"


class GetNumberFromStringTest : public ::testing::TestWithParam<std::pair<std::string, std::vector<int>>>
{
    // Test fixture class for parameterized tests
};

// Test case using the parameterized fixture
TEST_P(GetNumberFromStringTest, GetNumberFromStringTest)
{
    std::string input_string = GetParam().first;

    auto result = helpers::getNumbers<int>(input_string);

    std::vector<int> expected_output = GetParam().second;

    EXPECT_EQ(result, expected_output);
}

// Define the parameter values: {input_string, expected_output}
INSTANTIATE_TEST_CASE_P(Default, GetNumberFromStringTest,
    ::testing::Values(
        std::make_pair(std::string("1 2 3 4 5"), std::vector<int>{1, 2, 3, 4, 5}),
        std::make_pair(std::string("1123, 1232112 123,4123 ,52"), std::vector<int>{1123, 1232112, 123, 4123, 52}),
        std::make_pair(std::string("11,22,33,44,55"), std::vector<int>{11, 22, 33, 44, 55})
    ));