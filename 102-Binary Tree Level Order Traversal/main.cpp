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

//// dfs
// class Solution
// {
//     vector<vector<int>> ans;

// public:
//     vector<vector<int>> levelOrder(TreeNode *root)
//     {
//         dfs(root, 0);
//         return ans;
//     }

//     void dfs(TreeNode *node, int depth)
//     {
//         if (node == nullptr)
//         {
//             return;
//         }
//         if (ans.size() <= depth)
//         {
//             vector<int> newVect;
//             ans.push_back(newVect);
//         }
//         ans[depth].push_back(node->val);
//         dfs(node->left, depth + 1);
//         dfs(node->right, depth + 1);
//     }
// };

// bfs
class Solution
{

public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        if (root == nullptr)
        {
            return vector<vector<int>>();
        }

        vector<vector<int>> ans;
        queue<TreeNode *> que;
        que.push(root);
        while (!que.empty())
        {

            int level_size = que.size();
            vector<int> tempVect;
            tempVect.reserve(level_size);
            while (level_size > 0)
            {
                TreeNode *tempNode = que.front();
                que.pop();
                level_size--;
                tempVect.push_back(tempNode->val);
                if (tempNode->left != nullptr)
                {
                    que.push(tempNode->left);
                }
                if (tempNode->right != nullptr)
                {
                    que.push(tempNode->right);
                }
            }
            if (tempVect.size() > 0)
            {
                ans.push_back(tempVect);
            }
        }
        return ans;
    }
};

int main()
{
}