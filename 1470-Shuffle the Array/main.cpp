#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> shuffle(vector<int> &nums, int n)
    {
        vector<int> results(nums.size());
        int j = 0;
        for (int i = 0; i < nums.size() / 2; i++)
        {
            results[j] = nums[i];
            results[j + 1] = nums[n + i];
            j += 2;
        }
        return results;
    }
};