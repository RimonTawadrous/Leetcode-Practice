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

// TreeNode *trimBST(TreeNode *root, int low, int high)
// {
//     stack<TreeNode *> s;
//     if (root == nullptr)
//     {
//         return root;
//     }

//     while (root != nullptr && (root->val < low || root->val > high))
//     {
//         if (root->val < low)
//         {
//             root = root->right;
//         }
//         else if (root->val > high)
//         {
//             root = root->left;
//         }
//     }

//     if (root == nullptr)
//     {
//         return root;
//     }

//     s.push(root);
//     TreeNode *currentNode;
//     while (!s.empty())
//     {
//         currentNode = s.top();
//         s.pop();
//         // cout << "currentNode    =  " << currentNode->val << endl;

//         if (currentNode->left != nullptr)
//         {
//             // cout << "currentNode->left    =  " << currentNode->left->val << endl;
//             if (currentNode->left->val >= low)
//             {
//                 s.push(currentNode->left);
//                 // cout << "push    =  " << currentNode->left->val;
//             }
//             else
//             {
//                 if (currentNode->left->right != nullptr)
//                 {
//                     if (currentNode->left->right->val >= low && currentNode->left->right->val <= high)
//                     {
//                         // cout << "push    =  " << currentNode->left->right->val;
//                         s.push(currentNode->left->right);
//                         currentNode->left = currentNode->left->right;
//                     }
//                     else
//                     {
//                         // cout << " !push    =  " << currentNode->left->val;
//                         currentNode->left = nullptr;
//                     }
//                 }
//                 else
//                 {
//                     currentNode->left = nullptr;
//                 }
//             }
//         }

//         if (currentNode->right != nullptr)
//         {
//             if (currentNode->right->val <= high)
//             {
//                 s.push(currentNode->right);
//             }
//             else
//             {
//                 if (currentNode->right->left != nullptr)
//                 {
//                     if (currentNode->right->left->val >= low && currentNode->right->val <= high)
//                     {
//                         s.push(currentNode->right->left);
//                         currentNode->right = currentNode->left->right;
//                     }
//                     else
//                     {
//                         currentNode->right = nullptr;
//                     }
//                 }
//                 else
//                 {
//                     currentNode->right = nullptr;
//                 }
//             }
//         }
//     }
//     return root;
// }

TreeNode *trimBST(TreeNode *root, int low, int high)
{
    stack<TreeNode *> s;
    if (root == nullptr)
    {
        return root;
    }

    while (root != nullptr && (root->val < low || root->val > high))
    {
        if (root->val < low)
        {
            root = root->right;
        }
        else if (root->val > high)
        {
            root = root->left;
        }
    }

    if (root == nullptr)
    {
        return root;
    }

    s.push(root);
    TreeNode *currentNode;
    while (!s.empty())
    {
        currentNode = s.top();
        s.pop();
        TreeNode *leftNode = currentNode->left;
        TreeNode *rightNode = currentNode->right;

        // cout << "currentNode    =  " << currentNode->val << endl;
        while (leftNode != nullptr && (leftNode->val < low || leftNode->val > high))
        {
            if (leftNode->val < low)
            {
                leftNode = leftNode->right;
            }
            else if (leftNode->val > high)
            {
                leftNode = leftNode->left;
            }
        }
        while (rightNode != nullptr && (rightNode->val < low || rightNode->val > high))
        {
            if (rightNode->val < low)
            {
                rightNode = rightNode->right;
            }
            else if (rightNode->val > high)
            {
                rightNode = rightNode->left;
            }
        }
        currentNode->left = leftNode;
        currentNode->right = rightNode;

        if (leftNode != nullptr)
        {
            s.push(leftNode);
        }
        if (rightNode != nullptr)
        {
            s.push(rightNode);
        }
    }
    return root;
}

TreeNode *trimBST(TreeNode *root, int low, int high)
{
    if (root == nullptr)
    {
        return root;
    }

    if (root->val < low)
    {
        return trimBST(root->right, low, high);
    }
    if (root->val > high)
    {
        return trimBST(root->left, low, high);
    }

    root->left = trimBST(root->left, low, high);
    root->right = trimBST(root->right, low, high);
    return root;
}
int main()
{
}