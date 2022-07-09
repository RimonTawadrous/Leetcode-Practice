#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *deleteDuplicates(ListNode *head)
{
    ListNode *newHead = NULL;
    ListNode *curretNode = NULL;
    ListNode *skipNode = head;
    while (skipNode)
    {
        while (skipNode && skipNode->next && skipNode->val == skipNode->next->val)
        {
            while (skipNode->next && skipNode->val == skipNode->next->val)
            {
                skipNode = skipNode->next;
            }
            skipNode = skipNode->next;
        }
        if (!newHead)
        {
            newHead = skipNode;
            curretNode = newHead;
        }
        else
        {
            curretNode->next = skipNode;
            curretNode = curretNode->next;
        }
        if (skipNode)
        {
            skipNode = skipNode->next;
        }
    }
    return newHead;
}