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
public:
    bool isValidBST(TreeNode *root)
    {
        return helper(root, LONG_MIN, LONG_MAX);
    }
    bool helper(TreeNode *root, long int min, long int max)
    {
        if (root == nullptr)
        {
            return true;
        }

        if (root->val <= min || root->val >= max)
        {
            return false;
        }

        if (root->left != nullptr && (root->val <= root->left->val || root->left->val <= min || root->left->val >= max))
        {
            return false;
        }
        if (root->right != nullptr && (root->val >= root->right->val))
        {
            return false;
        }
        return helper(root->left, min, root->val) && helper(root->right, root->val, max);
    }
};

int main()
{
}