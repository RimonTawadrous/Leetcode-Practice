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

class Solution
{
private:
    TreeNode *frist;
    TreeNode *last;
    TreeNode *prev;
    TreeNode *middle;
    void inorder(TreeNode *node)
    {

        if (node == nullptr)
        {
            return;
        }
        inorder(node->left);
        if(prev != nullptr && (node->val < prev->val)){
            if(frist == nullptr){
                frist = prev;
                middle = node;
            }else{
                last = node;
            }
        }
        prev = node;
        inorder(node->right);
    }

public:
    void recoverTree(TreeNode *root)
    {
        frist = middle = last = prev = nullptr;
        inorder(root);
        if (frist && last)
        {
            swap(frist->val, last->val);
        }
        else if (frist && middle)
        {
            swap(frist->val, middle->val);
        }
    }
};

int main()
{
}