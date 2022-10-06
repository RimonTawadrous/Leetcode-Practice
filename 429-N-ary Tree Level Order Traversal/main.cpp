#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

// solution 1
class Solution
{
private:
    vector<vector<int>> res;

public:
    vector<vector<int>> levelOrder(Node *root)
    {
        if (root == nullptr)
        {
            return {};
        }
        helper(root, 0);
        return res;
    }
    void helper(Node *node, int height)
    {
        if (node == nullptr)
        {
            return;
        }

        if (res.size() == height)
        {
            res.push_back({node->val});
        }
        else
        {
            res[height].push_back(node->val);
        }
        if (res.size() == height + 1 && !node->children.empty())
        {
            res.push_back({});
        }
        for (Node *currentNode : node->children)
        {
            helper(currentNode, height + 1);
        }
    }
};

// solution 2
class Solution
{
private:
    vector<vector<int>> res;

public:
    vector<vector<int>> levelOrder(Node *root)
    {
        if (root == nullptr)
        {
            return {};
        }
        queue<Node *> qu;
        qu.push(root);
        while (!qu.empty())
        {
            int size = qu.size();
            vector<int> temp(size);
            for (int i = 0; i < size; i++)
            {
                Node *tempNode = qu.front();
                qu.pop();
                temp[i] = tempNode->val;
                for (Node *currentNode : tempNode->children)
                {
                    qu.push(currentNode);
                }
            }
            res.push_back(temp);
        }
        return res;
    }
};