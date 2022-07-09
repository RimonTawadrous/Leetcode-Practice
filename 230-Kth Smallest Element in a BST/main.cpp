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
// int kthSmallest(TreeNode *root, int k)
// {
//     if (root == nullptr)
//     {
//         return 0;
//     }
//     stack<TreeNode *> nodeStack;
//     unordered_set<TreeNode *> visited;
//     int num = 0;
//     nodeStack.push(root);
//     while (!nodeStack.empty())
//     {

//         TreeNode *topNode = nodeStack.top();
//         if (topNode->left != nullptr)
//         {
//             if (visited.find(topNode) == visited.end())
//             {
//                 nodeStack.push(topNode->left);
//             }
//             else
//             {
//             }
//         }
//         else
//         {
//             num++;
//             if (num == k)
//             {
//                 return topNode->val;
//             }
//             else
//             {
//                 if (topNode->right != nullptr)
//                 {
//                     if (visited.find(topNode->right) == visited.end())
//                     {
//                         nodeStack.push(topNode->right);
//                     }
//                     else
//                     {
//                     }
//                 }
//             }
//             nodeStack.pop();
//         }
//     }
// }

int kthSmallest(TreeNode *root, int k)
{
    return kthSmallest(root, k, 0);
}

int kthSmallest(TreeNode *root, int k, int number)
{
    static int res = 0;
    static bool foundVal = false;
    if (root == nullptr)
    {
        return 0;
    }
    int leftValue = kthSmallest(root->left, k, number) + 1;
    cout << " node value  = " << root->val << " leftValue = " << leftValue << endl;
    if (leftValue == k)
    {
        foundVal = true;
        res = root->val;
    }
    if (foundVal)
    {
        cout << " retrun res = " << res << endl;
        return res;
    }

    int rightValue = kthSmallest(root->right, k, number);

    return leftValue + rightValue + number;
}

[ 3, 1, 4, null, 2 ] 1
    [5, 3, 6, 2, 4, null, null, 1] 3
        [5, 3, 6, 2, 4, null, null, 1] 3
            [3, 1, 4, null, 2] 2
    [1, null, 2] 2

    int
    kthSmallest(TreeNode *root, int k)
{
    if (root == nullptr)
    {
        return
    }
    kthSmallest(root->left) return kthSmallest(root, k);
}

void searchValue(TreeNode *root, int k)
{
    int i;
    if (root == nullptr)
    {
        return;
    }
    i++;
    kthSmallest(root->left,k);
    i++
    kthSmallest(root,k);
    i++
    kthSmallest(root->right,k);
    return kthSmallest(root, k);
}