#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
TreeNode *convertBST(TreeNode *root)
{
    convertBST(root, 0);
    return root;
}

int convertBST(TreeNode *root, int number)
{
    if (root == nullptr)
    {
        return 0;
    }
    int value;
    if (root->right == nullptr)
    {
        value = number + root->val;
    }
    else
    {
        value = root->val + convertBST(root->right, number);
    }
    root->val = value;
    if (root->left)
    {
        return convertBST(root->left, value);
    }
    return value;
}

int main()
{
}