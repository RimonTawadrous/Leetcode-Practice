#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int maxNumber = nums[0], currentMax = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            currentMax = max(nums[i], nums[i - 1] + nums[i]);
            nums[i] = currentMax;
            if (currentMax > maxNumber)
            {
                maxNumber = currentMax;
            }
        }
        return maxNumber;
    }
};

int main()
{
}