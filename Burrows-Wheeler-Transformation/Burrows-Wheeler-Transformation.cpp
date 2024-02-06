#include <gtest/gtest.h>
#include "Burrows-Wheeler-Transformation.hpp"

struct BurrowsWheelerTransformation:public::testing::Test
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

// TEST_F(BurrowsWheelerTransformation, matrixTest)
// {
//     string inputStr = "bananabar";
//     vector <string> expectedMatrix = {"bananabar", "ananabarb", "nanabarba", "anabarban", "nabarbana", "abarbanan", "barbanana", "arbananab", "rbananaba"};
    
//     vector <string> resultMatrix = solution->getMatrix(inputStr);

//     EXPECT_EQ(expectedMatrix, resultMatrix);
// }

// TEST_F(BurrowsWheelerTransformation, sortedMatrixTest)
// {
//     vector <string> inputMatrix = {"bananabar", "ananabarb", "nanabarba", "anabarban", "nabarbana", "abarbanan", "barbanana", "arbananab", "rbananaba"};
//     vector <string> expectedMatrix = {"abarbanan", "anabarban", "ananabarb", "arbananab", "bananabar", "barbanana", "nabarbana", "nanabarba", "rbananaba"};

//     vector <string> resultMatrix = solution->getSortedMatrix(inputMatrix);

//     EXPECT_EQ(expectedMatrix, resultMatrix);
// }

// TEST_F(BurrowsWheelerTransformation, getEncodedStr)
// {
//     vector <string> sortedMatrix = {"abarbanan", "anabarban", "ananabarb", "arbananab", "bananabar", "barbanana", "nabarbana", "nanabarba", "rbananaba"};
//     string expectedResult = "nnbbraaaa";

//     string resultStr = solution->getEncodedStr(sortedMatrix);

//     EXPECT_EQ(expectedResult, resultStr);
// }

// TEST_F(BurrowsWheelerTransformation, getRowOfOriginalStr)
// {
//     string originalStr = "bananabar";
//     vector <string> sortedMatrix = {"abarbanan", "anabarban", "ananabarb", "arbananab", "bananabar", "barbanana", "nabarbana", "nanabarba", "rbananaba"};
//     int expectedRow = 4;

//     int resultRow = solution->getMatrixRow(originalStr, sortedMatrix);

//     EXPECT_EQ(expectedRow, resultRow);
// }

TEST_F(BurrowsWheelerTransformation, case1)
{
    string inputStr = "bananabar";
    pair<string, int> expectedEncodedOutput = {"nnbbraaaa", 4};
    
    pair<string, int> encodedOutput = solution->encode(inputStr);

    EXPECT_EQ(expectedEncodedOutput, encodedOutput);

    string decodedOutput = solution->decode(encodedOutput.first, encodedOutput.second);

    EXPECT_EQ(decodedOutput, inputStr);
}

TEST_F(BurrowsWheelerTransformation, case2)
{
    string inputStr = "Humble Bundle";
    pair<string, int> expectedEncodedOutput = {"e emnllbduuHB", 2};
    
    pair<string, int> encodedOutput = solution->encode(inputStr);

    EXPECT_EQ(expectedEncodedOutput, encodedOutput);

    string decodedOutput = solution->decode(encodedOutput.first, encodedOutput.second);

    EXPECT_EQ(decodedOutput, inputStr);

}

TEST_F(BurrowsWheelerTransformation, case3)
{
    string inputStr = "Mellow Yellow";
    pair<string, int> expectedEncodedOutput = {"ww MYeelllloo", 1};
    
    pair<string, int> encodedOutput = solution->encode(inputStr);

    EXPECT_EQ(expectedEncodedOutput, encodedOutput);

    string decodedOutput = solution->decode(encodedOutput.first, encodedOutput.second);

    EXPECT_EQ(decodedOutput, inputStr);
}
