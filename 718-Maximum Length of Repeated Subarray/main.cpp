#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // int findLength(vector<int> &nums1, vector<int> &nums2)
    // {
    //     vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1, 0));
    //     int maxLength = 0;
    //     for (int i = 1; i < nums1.size() + 1; i++)
    //     {
    //         for (int j = 1; j < nums2.size() + 1; j++)
    //         {
    //             if (nums1[i] == nums2[j])
    //             {
    //                 dp[i][j] = dp[i - 1][j - 1] + 1;
    //                 maxLength = max(maxLength, dp[i][j]);
    //             }
    //             else
    //             {
    //                 dp[i][j] = 0;
    //             }
    //         }
    //     }
    //     return maxLength;
    // }

    int findLength(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> dp(nums1.size() + 1);
        int maxLength = 0;
        for (int i = 0; i < nums1.size(); i++)
        {
            for (int j = nums2.size() - 1; j >= 0; j--)
            {
                if (nums1[i] == nums2[j])
                {
                    dp[j + 1] = dp[j] + 1;
                    maxLength = max(maxLength, dp[j + 1]);
                }
                else
                {
                    dp[j + 1] = 0;
                }
            }
        }
        return maxLength;
    }
};

int main()
{
}
