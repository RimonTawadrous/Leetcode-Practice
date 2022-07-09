#include <bits/stdc++.h>
using namespace std;

// bool search(vector<int> &nums, int target)
// {
//     int lo = 0, hi = nums.size() - 1;
//     int mid = hi / 2;

//     while (lo <= hi)
//     {
//         if (nums[mid] == target)
//         {
//             return true;
//         }
//         else if (nums[mid] < target && target <= nums[hi])
//         {
//             lo = mid + 1;
//         }
//         else if (target < nums[mid] && target >= nums[hi])
//         {
//             lo = mid + 1;
//         }
//         else if (nums[mid] < target && target >= nums[hi])
//         {
//             hi = mid - 1;
//         }
//         else if (target < nums[mid])
//         {
//             hi = mid - 1;
//         }
//         // cout << " lo = " << lo << endl;
//         // cout << " mid = " << mid << endl;
//         // cout << " hi = " << hi << endl;

//         mid = lo + (hi - lo) / 2;
//     }

//     for (size_t i = 0; i < nums.size(); i++)
//     {
//         if (nums[i] == target)
//         {
//             return true;
//         }
//     }

//     return false;
// }

// bool search(vector<int> &nums, int target)
// {
//     int lo = 0, hi = nums.size() - 1;
//     int mid = hi / 2;

//     while (lo <= hi)
//     {
//         if (nums[mid] == target)
//         {
//             return true;
//         }
//         else if (nums[mid] == nums[lo] && nums[mid] == nums[hi])
//         {

//             lo++;
//             hi--;
//         }
//         else if (nums[mid] < target && target <= nums[hi])
//         {
//             lo = mid + 1;
//         }
//         else if (target < nums[mid] && target >= nums[hi])
//         {
//             lo = mid + 1;
//         }
//         else if (nums[mid] < target && target >= nums[hi])
//         {
//             hi = mid - 1;
//         }
//         else if (target < nums[mid])
//         {
//             hi = mid - 1;
//         }
//         // cout << " lo = " << lo << endl;
//         // cout << " mid = " << mid << endl;
//         // cout << " hi = " << hi << endl;

//         mid = lo + (hi - lo) / 2;
//     }
//     return false;
// }

bool search(vector<int> &nums, int target)
{
    int lo = 0, hi = nums.size() - 1;
    int mid = hi / 2;

    while (lo <= hi)
    {
        if (nums[mid] == target)
        {
            return true;
        }
        else if (nums[mid] == nums[lo] && nums[mid] == nums[hi])
        {

            lo++;
            hi--;
        }
        else if (nums[mid] >= nums[lo])
        {
            if (target < nums[mid] && target >= nums[lo])
            {
                hi = mid - 1;
            }
            else
            {
                lo = mid + 1;
            }
        }

        else
        {
            if (target > nums[mid] && target <= nums[hi])
            {
                lo = mid + 1;
            }
            else
            {
                hi = mid - 1;
            }
        }
        mid = lo + (hi - lo) / 2;
    }
    return false;
}

int main()
{
    vector<int> nums = {1, 0, 1, 1, 1};
    cout << search(nums, 0) << endl;
}