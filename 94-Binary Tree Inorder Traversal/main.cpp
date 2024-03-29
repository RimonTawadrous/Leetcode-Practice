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
    vector<int> ans;

public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        helper(root);
        return ans;
    }
    void helper(TreeNode *node)
    {

        if (!node)
        {
            return;
        }
        helper(node->left);
        ans.push_back(node->val);
        helper(node->right);
    }
};

int main()
{
}