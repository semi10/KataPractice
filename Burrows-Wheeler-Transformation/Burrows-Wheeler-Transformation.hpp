// Burrows-Wheeler-Transformation
// https://www.codewars.com/kata/54ce4c6804fcc440a1000ecb/train/cpp

#ifndef BURROW_WHEELER_TRANSFORMATION_SRC
#define BURROW_WHEELER_TRANSFORMATION_SRC

#include <string>
#include <utility>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
    public:

    vector<string> getMatrix(const string &s)
    {
        vector <string> matrixStr;
        const int strLen = s.length();

        for(int i = 0; i < strLen; i++)
        {
            string tmpStr ="";
            int index = 0;
            for (int j = 0; j < strLen; j++)
            {
                index = (j+i) % strLen;
                tmpStr += s[index];
            }
            
            matrixStr.push_back(tmpStr);
        }

        return matrixStr;
    }

    vector <string> getSortedMatrix(const vector <string> &s)
    {
        vector <string> matrix = s;
        sort(matrix.begin(), matrix.end(), less<string>());

        return matrix;
    }

    int getMatrixRow(const string &originalStr, const vector <string> &s)
    {
        const int length = s.size();
        for (int i = 0; i < length; i++)
        {
            if (originalStr == s[i])
                return i;
        }

        return -1;
    }

    string getEncodedStr(vector <string> &s)
    {
        string resultStr ="";
        const int length = s.size();
        for(int i = 0; i < length; i++)
        {
            resultStr += s[i][length-1];
        }

        return resultStr;
    }

    string decode(const string &s, int n) {
        vector <string> matrixStr;
        const int length = s.size();

        for (int i = 0; i < length; i++)
        {
            matrixStr.push_back("");
        }

        for (int i = 0; i < length; i++)
        {
            for(int j = 0; j < length; j++)
            {
                matrixStr[j] = s[j] + matrixStr[j];
            }
            
            sort(matrixStr.begin(), matrixStr.end(), less<string>());
        }

        return matrixStr[n];
    }

    pair<string, int> encode(const string &s) {

        vector <string> unsortedMatrix = getMatrix(s);
        vector <string> sortedMatrix = getSortedMatrix(unsortedMatrix);
        int index = getMatrixRow(s, sortedMatrix);
        string encodedStr = getEncodedStr(sortedMatrix);

        return make_pair(encodedStr, index);
    }
};

#endif