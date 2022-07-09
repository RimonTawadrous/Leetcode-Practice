#include <bits/stdc++.h>
using namespace std;
int wiggleMaxLength(vector<int> &nums)
{
    int prevDiff = 0, diff = 0, count = 1;
    if (nums.size() < 2)
    {
        return nums.size();
    }
    prevDiff = nums[1] - nums[0];
    count = prevDiff != 0 ? 2 : 1;
    for (int i = 2; i < nums.size(); i++)
    {
        diff = nums[i] - nums[i - 1];
        if ((diff > 0 && prevDiff <= 0) || (diff < 0 && prevDiff >= 0))
        {
            prevDiff = diff;
            count++;
        }
    }
    return count;
}

int main()
{
}