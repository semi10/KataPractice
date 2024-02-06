#ifndef SUBARRAY_WITH_GIVEN_SUM_SRC
#define SUBARRAY_WITH_GIVEN_SUM_SRC

#include <vector>
#include <iostream>
#include <ranges>
using namespace std;

class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int>arr, int n, long long s)
    {
        vector<int> answer;
        int beginIndex = 0;
        int sum = 0;
        
        for (int i = 0; i < n; i++)
        {
            //cout << beginIndex << "-" << i << " " << sum << endl;
            sum += arr[i];

            while(sum > s) 
            {
                sum -= arr[beginIndex++];
            }

            if(sum == s)
            {
                if (beginIndex > i) break;
                answer.push_back(beginIndex + 1);
                answer.push_back(i + 1);
                return answer;
            }
        }

        answer.push_back(-1);
        return answer; 
    }
};

#endif