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
    void dfs(vector<vector<int>> &ans, vector<int> &path, TreeNode *node, int targetSum)
    {

        if (node == nullptr)
        {
            return;
        }
        path.push_back(node->val);
        int sum = accumulate(path.begin(), path.end(), 0);
        if (node->left != nullptr)
        {
            dfs(ans, path, node->left, targetSum);
        }
        if (node->right != nullptr)
        {
            dfs(ans, path, node->right, targetSum);
        }
        if (node->left == nullptr && node->right == nullptr)
        {
            if (sum == targetSum)
            {
                ans.push_back(path);
            }
        }
        path.pop_back();
    }

public:
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        vector<vector<int>> ans;
        vector<int> path;
        dfs(ans, path, root, targetSum);
        return ans;
    }
};

int main()
{
}