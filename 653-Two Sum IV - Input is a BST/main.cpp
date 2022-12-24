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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution
{
private:
    bool found(int number, TreeNode *root)
    {
        TreeNode *currentNode = root;
        while (currentNode != nullptr)
        {
            if (currentNode->val == number)
            {
                return true;
            }
            else if (currentNode->val > number)
            {
                currentNode = currentNode->left;
            }
            else
            {
                currentNode = currentNode->right;
            }
        }
        return false;
    }

public:
    bool findTarget(TreeNode *root, int k)
    {
        int sum = 0;
        TreeNode *currentNode = root;
        TreeNode *tempNode;
        queue<TreeNode *> q;
        q.push(root);
        int tempSize = 0;
        while (!q.empty())
        {
            tempSize = q.size();
            while (tempSize)
            {
                tempSize--;
                tempNode = q.front();
                if (found((k - tempNode->val), root) && (k - tempNode->val != tempNode->val))
                {
                    return true;
                }

                if (tempNode->left != nullptr)
                {
                    q.push(tempNode->left);
                }
                if (tempNode->right != nullptr)
                {
                    q.push(tempNode->right);
                }
                q.pop();
            }
        }
        return false;
    }
};