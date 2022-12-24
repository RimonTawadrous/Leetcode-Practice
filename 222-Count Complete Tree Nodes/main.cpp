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

// class Solution
// {
// private:
//     int count;

// public:
//     int countNodes(TreeNode *root)
//     {
//         count = 0;
//         dfs(root);
//         return count;
//     }
//     void dfs(TreeNode *node)
//     {
//         if (node == nullptr)
//         {
//             return;
//         }
//         count++;
//         dfs(node->left);
//         dfs(node->right);
//     }
// };

class Solution
{
private:
    int count;
    int treeHeight(TreeNode *root)
    {
        int height = 0;
        TreeNode *currentNode = root;
        while (currentNode != nullptr)
        {
            height++;
            currentNode = currentNode->left;
        }
        return height;
    }

public:
    int countNodes(TreeNode *root)
    {
        int treeHegiht = treeHeight(root);
        count = pow(2, treeHegiht) - 1;
        dfs(root, treeHegiht, 1);
        return count;
    }

    bool dfs(TreeNode *node, int treeHegiht, int currentHegiht)
    {
        if (currentHegiht <= treeHegiht)
        {
            if (!node)
            {
                count--;
                return false;
            }
            if (!node->right)
            {
                count--;
                if (!node->left)
                {
                    count--;
                }
                else
                {
                    dfs(node->left, treeHegiht, currentHegiht + 1);
                }
            }
            else
            {
                dfs(node->right, treeHegiht, currentHegiht + 1);
            }
        }
        return false;
    }
}