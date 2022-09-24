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
    int maxCount;

public:
    int longestConsecutive(TreeNode *root)
    {
        maxCount = 1;
        helper(root->left, root->val, 1);
        helper(root->right, root->val, 1);
    }

    void helper(TreeNode *node, int prevVal, int prevCount)
    {
        if (node == nullptr)
        {
            return;
        }

        if (node->val == prevVal - 1)
        {
            prevCount++;
        }
        else
        {
            prevCount = 1;
        }

        if (prevCount > maxCount)
        {
            maxCount = prevCount;
        }
        helper(node->left, node->val, prevCount);
        helper(node->right, node->val, prevCount);
    }
};

int main()
{
}