#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

// class Solution
// {
// private:
//     int preorderIndex;

// public:
//     TreeNode *dfs(vector<int> &preorder, int preorderIndex, vector<int> &inorder, int start, int last)
//     {
//         if (preorderIndex >= preorder.size() || start < 0 || last >= inorder.size())
//         {
//             return nullptr;
//         }
//         int mid = start + (start + last) / 2;
//         TreeNode *root = new TreeNode(preorder[preorderIndex]);
//         cout << "root " << preorder[preorderIndex] << endl;
//         if (mid > start)
//         {
//             preorderIndex++;
//             cout << "left " << preorder[preorderIndex] << endl;
//             root->left = dfs(preorder, preorderIndex, inorder, 0, mid);
//         }
//         if (last > mid + 1)
//             preorderIndex++;
//         cout << "right " << preorder[preorderIndex] << endl;
//         root->right = dfs(preorder, preorderIndex, inorder, mid + 1, last);

//         return root;
//     }

//     TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
//     {
//         if (preorder.size() == 0)
//         {
//             return nullptr;
//         }
//         TreeNode *root = new TreeNode(preorder[0]);
//         int mid = 0;
//         for (int value : inorder)
//         {
//             if (value == preorder[0])
//             {
//                 break;
//             }
//             mid++;
//         }
//         preorderIndex = 1;
//         root->left = dfs(preorder, preorderIndex, inorder, 0, mid);
//         preorderIndex++;
//         cout << "right " << preorder[preorderIndex] << endl;
//         root->right = dfs(preorder, preorderIndex, inorder, mid + 1, preorder.size() - 1);
//         return root;
//     }
// };

class Solution
{
public:
    unordered_map<int, int> inorder_indices;

    TreeNode *buildTree(vector<int> &preorder, int prestart, int preend,
                        vector<int> &inorder, int instart, int inend)
    {
        //[prestart, preend], [inorder, inend] are inclusive
        if (prestart > preend)
            return nullptr;

        TreeNode *root = new TreeNode(preorder[prestart]);

        // int split = find(inorder.begin()+instart,
        //     inorder.begin()+inend+1, root->val)-inorder.begin();
        int split = inorder_indices[root->val];
        int left_size = split - instart;

        root->left = buildTree(preorder, prestart + 1, prestart + 1 + left_size - 1,
                               inorder, instart, split - 1);

        root->right = buildTree(preorder, prestart + left_size + 1, preend,
                                inorder, split + 1, inend);

        return root;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        int n = preorder.size();

        for (int i = 0; i < n; ++i)
        {
            inorder_indices[inorder[i]] = i;
        }

        return buildTree(preorder, 0, n - 1, inorder, 0, n - 1);
    }
};

int main() {}