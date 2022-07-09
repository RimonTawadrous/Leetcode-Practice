#include <bits/stdc++.h>
using namespace std;

int minMoves2(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    long long int count = 0;
    int median = 0;
    int numsSize = nums.size();
    if (numsSize % 2 == 0)
    {
        median = ceil((nums[numsSize / 2] + nums[numsSize / 2 - 1]) / 2);
    }
    else
    {
        median = nums[numsSize / 2];
    }
    for (size_t i = 0; i < nums.size(); i++)
    {
        count += abs(nums[i] - median);
    }

    return count;
}
int main()
{
}