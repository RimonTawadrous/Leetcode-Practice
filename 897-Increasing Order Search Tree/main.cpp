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

TreeNode *increasingBST(TreeNode *root)
{
    stack<TreeNode *> NodeStack;
    unordered_set<TreeNode *> visited;
    TreeNode *currentNode = nullptr, *newRoot = nullptr;
    if (root)
    {
        NodeStack.push(root);
    }
    while (!NodeStack.empty())
    {
        TreeNode *topNode = NodeStack.top();
        if (topNode->left != nullptr && visited.find(topNode->left) == visited.end())
        {
            NodeStack.push(topNode->left);
        }
        else
        {
            cout << " TN = " << topNode->val << "  ";
            if (newRoot == nullptr)
            {
                newRoot = topNode;
                currentNode = newRoot;
                visited.insert(currentNode);
            }
            else
            {
                currentNode->right = topNode;
                currentNode = currentNode->right;
                visited.insert(topNode);
            }
            NodeStack.pop();
            if (currentNode->right != nullptr)
            {
                NodeStack.push(currentNode->right);
            }
            currentNode->left = nullptr;
            currentNode->right = nullptr;
        }
    }
    return newRoot;
}