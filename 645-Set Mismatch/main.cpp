#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // vector<int> findErrorNums(vector<int> &nums)
    // {
    //     if (nums.empty())
    //     {
    //         return {};
    //     }
    //     unordered_set<int> visitedValues;
    //     int number = 0 ;
    //     for (int i = 0; i < nums.size(); i++)
    //     {
    //         if (visitedValues.find(nums[i]) != visitedValues.end())
    //         {
    //             number = nums[i];
    //         }
    //         visitedValues.insert(nums[i]);
    //     }

    //     for (int i = 1; i < nums.size() + 1; i++)
    //     {
    //         if (visitedValues.find(i) == visitedValues.end())
    //         {
    //             return {number, i};
    //         }
    //     }

    //     return {number, number + 1};
    // }

    vector<int> findErrorNums(vector<int> &nums)
    {
        if (nums.empty())
        {
            return {};
        }
        vector<int> res(2);
        for (int num : nums)
        {
            if (nums[abs(num) - 1] < 0)
            {
                res[0] = abs(num);
            }
            else
            {
                nums[abs(num) - 1] *= -1;
            }
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0)
            {
                res[1] = i + 1;
            }
        }

        return res;
    }
};

int main()