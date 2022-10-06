#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
private:
    TreeNode *root;

public:
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return dive(nums, 0, nums.size() - 1);
    }

    TreeNode *dive(vector<int> &nums, int left, int right)
    {
        int mid = left + (right - left) / 2;
        if (left > right)
        {
            return nullptr;
        }
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = dive(nums, left, mid - 1);
        root->right = dive(nums, mid + 1, right);
        return root;
    }
};

int main()
{
    vector<int> nums = {-10, -3, 0, 5, 9};
    Solution s;

    s.sortedArrayToBST(nums);
}