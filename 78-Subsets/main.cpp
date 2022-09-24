#include <bits/stdc++.h>
using namespace std;

// class Solution
// {
// private:
//     void dfs(int index, vector<int> &nums, vector<vector<int>> &ans, vector<int> subset)
//     {
//         if (index == nums.size())
//         {
//             ans.push_back(subset);
//             return;
//         }
//         else
//         {
//             subset.push_back(nums[index]);
//             dfs(index + 1, nums, ans, subset);

//             subset.pop_back();
//             dfs(index + 1, nums, ans, subset);
//         }
//     }

// public:
//     vector<vector<int>> subsets(vector<int> &nums)
//     {
//         vector<vector<int>> ans;
//         vector<int> subset;
//         dfs(0, nums, ans, subset);
//         return ans;
//     }
// };

class Solution
{
public:
    void backtrack(vector<vector<int>> &ans, vector<int> &subset, vector<int> &nums, int start)
    {
        ans.push_back(subset);
        for (int i = start; i < nums.size(); i++)
        {
            subset.push_back(nums[i]);
            backtrack(ans, subset, nums, i + 1);
            subset.pop_back();
        }
    };

    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> subset;

        backtrack(ans, subset, nums, 0);

        return ans;
    }
};
int main()
{
    vector<vector<int>> ans;
    Solution s;
    vector<int> test = {1, 2, 3};
    ans = s.subsets(test);

    for (vector<int> vect : ans)
    {
        for (int num : vect)
        {
            cout << num << " ";
        }
        cout << endl;
    }
}