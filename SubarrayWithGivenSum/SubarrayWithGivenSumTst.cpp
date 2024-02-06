#include <gtest/gtest.h>
#include "SubarrayWithGivenSumSrc.hpp"

struct SubarrayWithGivenSumTst:public::testing::Test
{
    Solution* solution;

    virtual void SetUp() override 
    {
        solution = new Solution();
    }

    virtual void TearDown() override 
    {
        if (solution)
            delete(solution);
    }
};

TEST_F(SubarrayWithGivenSumTst, Example1)
{
    vector<int> request {1,2,3,7,5};
    vector<int> expected {2,4};
    int requstedSum = 12;
    vector<int> response;

    response = solution->subarraySum(request, request.size(), requstedSum);
    EXPECT_EQ(expected,response);
}

TEST_F(SubarrayWithGivenSumTst, Example2)
{
    vector<int> request {1,2,3,4,5,6,7,8,9,10};
    vector<int> expected {1,5};
    int requstedSum = 15;
    vector<int> response;

    response = solution->subarraySum(request, request.size(), requstedSum);
    EXPECT_EQ(expected,response);
}

TEST_F(SubarrayWithGivenSumTst, Example3)
{
    vector<int> request {135,101,170,125,79,159,163,65,106,146,82,28,162,92,196,143,28,37,192,5,103,154,93,183,22,117,119,96,48,127,172,139,70,113,68,100,36,95,104,12,123,134};
    vector<int> expected {38,42};
    int requstedSum = 468;
    vector<int> response;

    response = solution->subarraySum(request, request.size(), requstedSum);
    EXPECT_EQ(expected,response);
}

TEST_F(SubarrayWithGivenSumTst, Example4)
{
    vector<int> request {1,2,3,4};
    vector<int> expected {-1};
    int requstedSum = 0;
    vector<int> response;

    response = solution->subarraySum(request, request.size(), requstedSum);
    EXPECT_EQ(expected,response);
}