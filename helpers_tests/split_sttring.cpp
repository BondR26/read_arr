#include "pch.h"

class SplitStringTest : public ::testing::TestWithParam<std::tuple<std::string, char, std::vector<std::string>>>
{
    // Test fixture class for parameterized tests
};

// Define the parameter values: {input_string, delimiter, expected_output}
INSTANTIATE_TEST_CASE_P(Default
    , SplitStringTest
    , ::testing::Values(
        std::make_tuple("hi.how.are.you.i.am.under.the.water"
            , '.'
            , std::vector<std::string>{"hi", "how", "are", "you", "i", "am", "under", "the", "water"})
        , std::make_tuple("apple,orange,banana,grape"
            , ','
            , std::vector<std::string>{"apple", "orange", "banana", "grape"})
        , std::make_tuple("1 2 3 4 5"
            , ' '
            , std::vector<std::string>{"1", "2", "3", "4", "5"})
    ));

// Test case using the parameterized fixture
TEST_P(SplitStringTest, SplitStringTest)
{
    std::string input_string = std::get<0>(GetParam());
    char delimiter = std::get<1>(GetParam());
    std::vector<std::string> expected_output = std::get<2>(GetParam());

    auto result = helpers::splitString(input_string, delimiter);

    EXPECT_EQ(result, expected_output);
}