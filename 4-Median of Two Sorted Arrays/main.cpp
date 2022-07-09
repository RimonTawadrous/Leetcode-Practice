#include <bits/stdc++.h>
using namespace std;

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    if (nums1.size() > nums2.size())
    {
        return findMedianSortedArrays(nums2, nums1);
    }
    int smallVectSize = nums1.size(), largeVectSize = nums2.size();
    int low = 0, high = smallVectSize, totalSize = smallVectSize + largeVectSize, halfSize = (smallVectSize + largeVectSize) / 2;
    int partition1, partition2;
    int num1LeftMax, num1RightMin, num2LeftMax, num2RightMin;
    double ans = 0;

    while (low <= high)
    {
        partition1 = low + (high - low) / 2;
        partition2 = halfSize - partition1;
        num1LeftMax = partition1 == 0 ? INT_MIN : nums1[partition1 - 1];
        num1RightMin = partition1 == smallVectSize ? INT_MAX : nums1[partition1];

        num2LeftMax = partition2 == 0 ? INT_MIN : nums2[partition2 - 1];
        num2RightMin = partition2 == largeVectSize ? INT_MAX : nums2[partition2];
        if (num1LeftMax <= num2RightMin && num2LeftMax <= num1RightMin)
        {
            if (totalSize % 2 == 0)
            {
                ans = (double)(max(num1LeftMax, num2LeftMax) + min(num1RightMin, num2RightMin)) / 2.0;
                return ans;
            }
            else
            {
                ans = min(num1RightMin, num2RightMin);
                return ans;
            }
        }
        else if (num1LeftMax > num2RightMin)
        {
            high = partition1 - 1;
        }
        else
        {
            low = partition1 + 1;
        }
    }
    return ans;
}

int main()
{
    // vector<int> nums1 = {1, 2, 3, 4, 5, 6, 7, 8};
    // vector<int> nums2 = {1, 2, 3, 4};

    // vector<int> nums1 = {1, 2};
    // vector<int> nums2 = {3, 4};

    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};

    cout << findMedianSortedArrays(nums1, nums2) << endl;
}
