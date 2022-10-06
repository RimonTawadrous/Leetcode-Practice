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
    int count = 0;

public:
    int goodNodes(TreeNode *root)
    {
        checkNode(root, INT_MIN);
        return count;
    }
    void checkNode(TreeNode *node, int maxNumber)
    {
        if (node == nullptr)
        {
            return;
        }
        if (maxNumber <= node->val)
        {
            count++;
        }
        int newMax = max(maxNumber, node->val);
        checkNode(node->left, newMax);
        checkNode(node->right, newMax);
    }
};

int mian()
{
}