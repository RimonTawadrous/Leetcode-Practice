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
    TreeNode *pruneTree(TreeNode *root)
    {

        int count = helper(root);
        if (count == 0)
        {
            return NULL;
        }
        return root;
    }

    int helper(TreeNode *node)
    {
        if (node == nullptr)
        {
            return 0;
        }
        int leftCount = 0, rightCount = 0;
        leftCount = helper(node->left);
        rightCount = helper(node->right);

        if (leftCount == 0)
        {
            node->left = nullptr;
        }
        if (rightCount == 0)
        {
            node->right = nullptr;
        }

        return leftCount + rightCount + node->val;
    }
};

int main()
{
}