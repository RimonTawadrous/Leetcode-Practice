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
    TreeNode *addOneRow(TreeNode *root, int val, int depth)
    {
        if (depth == 1)
        {
            TreeNode *newNode = new TreeNode(val);
            newNode->left = root;
            root = newNode;
            return root;
        }
        int currentDepth = 0;
        queue<TreeNode *> nodesQueue;
        nodesQueue.push(root);
        int tempSize = 0;
        while (!nodesQueue.empty())
        {
            currentDepth++;
            tempSize = nodesQueue.size();
            if (depth - 1 == currentDepth)
            {
                while (tempSize > 0)
                {
                    TreeNode *tempNode = nodesQueue.front();
                    nodesQueue.pop();
                    TreeNode *newLeftNode = new TreeNode(val);
                    TreeNode *newRightNode = new TreeNode(val);
                    newLeftNode->left = tempNode->left;
                    newRightNode->right = tempNode->right;
                    tempNode->left = newLeftNode;
                    tempNode->right = newRightNode;
                    tempSize--;
                }
                return root;
            }
            while (tempSize > 0)
            {
                TreeNode *tempNode = nodesQueue.front();
                nodesQueue.pop();
                if (tempNode->left != nullptr)
                {
                    nodesQueue.push(tempNode->left);
                }
                if (tempNode->right != nullptr)
                {
                    nodesQueue.push(tempNode->right);
                }
                tempSize--;
            }
        }
        return root;
    }
};

int mian()
{
}