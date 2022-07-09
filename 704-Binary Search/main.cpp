#include <bits/stdc++.h>
using namespace std;

int search(vector<int> &nums, int target)
{
    if (!nums.size())
    {
        return -1;
    }
    int hi = nums.size() - 1;
    int lo = 0;
    int mid = nums.size() / 2;

    while (lo <= hi)
    {
        if (nums[mid] == target)
        {
            return mid;
        }
        if (nums[mid] > target)
        {
            hi = mid-1;
        }
        else
        {
            lo = mid+1;
        }

        mid = lo + (hi-lo)/2;
    }
    return -1;
}

int main()
{
    vector<int> nums = {-1,0,3,5,9,12};

    cout << search(nums,10) << endl;
    return 0;
}