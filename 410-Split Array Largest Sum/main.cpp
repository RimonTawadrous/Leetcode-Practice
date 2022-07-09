#include <bits/stdc++.h>
using namespace std;

// int splitArray(vector<int> &nums, int m)
// {

//     int lo = INT_MIN, hi = 0, mid, parts;
//     vector<int> sums;
//     sums[0] = nums[0];
//     for (size_t i = 1; i < nums.size(); i++)
//     {
//         if (nums[i] > lo)
//         {
//             lo = nums[i];
//         }
//         sums[i] = sums[i - 1] + nums[i];
//     }
//     hi = sums[sums.size() - 1];

//     while (lo <= hi)
//     {
//         mid = lo + (hi - lo) / 2;
//         if (sums[mid] == mid)
//         {
//         }
//         else
//         {
//         }
//     }
// }

bool check(int mid, vector<int> &nums, int K)
{
    int count = 0;
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {

        // If individual element is greater
        // maximum possible sum
        if (nums[i] > mid)
            return false;

        // Increase sum of current sub - array
        sum += nums[i];

        // If the sum is greater than
        // mid increase count
        if (sum > mid)
        {
            count++;
            sum = nums[i];
        }
    }
    count++;

    // Check condition
    if (count <= K)
        return true;
    return false;
}

int splitArray(vector<int> &nums, int m)
{
    int lo = INT_MIN, hi = 0, mid, parts;
    hi = nums[0];

    for (size_t i = 1; i < nums.size(); i++)
    {
        if (nums[i] > lo)
        {
            lo = nums[i];
        }
        hi = hi + nums[i];
    }

    while (lo <= hi)
    {
        mid = (hi + lo) / 2;
        if (check(mid, nums, m))
        {
            parts = mid;
            hi = mid - 1;
        }
        else
        {
            lo = mid + 1;
        }
    }
}

int main()
{
}