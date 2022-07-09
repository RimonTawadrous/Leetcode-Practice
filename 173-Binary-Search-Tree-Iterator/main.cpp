#include <bits/stdc++.h>
#include <vector>
#include <stack>
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

// class BSTIterator
// {
// private:
//     vector<int> inOrder;
//     int current = 0;

//     void build(TreeNode *root)
//     {
//         if (root == nullptr)
//         {
//             return;
//         }
//         build(root->left);
//         inOrder.push_back(root->val);
//         build(root->right);
//     }

// public:
//     BSTIterator(TreeNode *root)
//     {
//         this->build(root->left);
//     }

//     int next()
//     {
//         return inOrder[this->current++];
//     }

//     bool hasNext()
//     {
//         if (this->current < inOrder.size())
//         {
//             return true;
//         }
//         return false;
//     }
// };

class BSTIterator
{
private:
    stack<TreeNode *> nodeStack;
    int current = 0;

public:
    BSTIterator(TreeNode *root)
    {
        while (root)
        {
            nodeStack.push(root);
            root = root->left;
        }
    }

    int next()
    {
        TreeNode *res = nodeStack.top();
        nodeStack.pop();
        TreeNode *current = res->right;
        while (current)
        {
            nodeStack.push(current);
            current = current->left;
        }
        return res->val;
    }

    bool hasNext()
    {
        return !nodeStack.empty();
    }
};

int main()
{
}