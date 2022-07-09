#include <bits/stdc++.h>
using namespace std;
// sorrt

// int findKthLargest(vector<int> &nums, int k)
// {
//     sort(nums.begin(), nums.end(), greater<int>());
//     return nums[k - 1];
// }

// heap n+k.log(n) space (n)
// int findKthLargest(vector<int> &nums, int k)
// {
//     priority_queue<int> temp;
//     for (size_t i = 0; i < nums.size(); i++)
//     {
//         temp.push(nums[i]);
//     }

//     while (k > 1)
//     {
//         temp.pop();
//         k--;
//     }
//     return temp.top();
// }

// heap nlog(k)  space k
// int findKthLargest(vector<int> &nums, int k)
// {
//     priority_queue<int, vector<int>, greater<int>> temp;
//     for (size_t i = 0; i < nums.size(); i++)
//     {
//         if (temp.size() < k)
//         {
//             temp.push(nums[i]);
//         }
//         else
//         {
//             if (nums[i] > temp.top())
//             {
//                 temp.pop();
//                 temp.push(nums[i]);
//             }
//         }
//     }

//     return temp.top();
// }

// quick select o(n^2) omega of(n) space(1)
//  void swap(vector<int> &nums, int first, int second)
//  {
//      if (first == second)
//          return;
//      int temp = nums[first];
//      nums[first] = nums[second];
//      nums[second] = temp;
//  }

// int findKthLargest(vector<int> &nums, int k)
// {
//     int k_index = nums.size() - k;
//     int left = 0, right = nums.size() - 1;
//     int pivot = nums[right], p = left;

//     while (left <= right)
//     {
//         pivot = nums[right];
//         p = left;
//         for (size_t i = left; i < right; i++)
//         {
//             if (nums[i] <= pivot)
//             {
//                 swap(nums, p, i);
//                 p++;
//             }
//         }
//         swap(nums, p, right);

//         if (p > k_index)
//         {
//             right = p - 1;
//         }
//         else if (p < k_index)
//         {
//             left = p + 1;
//         }
//         else
//         {
//             return nums[p];
//         }
//     }

//     return 0;
// }

int main()
{

    // vector<int> test = {3, 2, 1, 5, 6, 4};
    // cout << findKthLargest(test, 2) << endl;

    vector<int> test = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    cout << findKthLargest(test, 4) << endl;
}