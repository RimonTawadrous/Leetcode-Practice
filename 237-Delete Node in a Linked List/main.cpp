#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    void deleteNode(ListNode *node)
    {
        ListNode *nextNode = node->next;

        while (nextNode->next)
        {
            node->val = nextNode->val;
            node = nextNode;
            nextNode = nextNode->next;
        }
        node->val = nextNode->val;
        node->next = nullptr;
        delete nextNode;
    }
};

int main()
{
}