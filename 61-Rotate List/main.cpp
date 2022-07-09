#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *rotateRight(ListNode *head, int k)
{
    ListNode *iteratorNode = head;
    int listLength = 1;
    if (!head)
    {
        return head;
    }

    while (iteratorNode->next)
    {
        listLength++;
        iteratorNode = iteratorNode->next;
    }
    k = k % listLength;
    int stopLegnth = listLength - k;
    if (stopLegnth < 1 || k == 0)
    {
        return head;
    }
    iteratorNode = head;
    while (stopLegnth > 1)
    {

        stopLegnth--;
        iteratorNode = iteratorNode->next;
    }
    ListNode *NodeToBeShifted = iteratorNode->next;
    iteratorNode->next = nullptr;
    iteratorNode = NodeToBeShifted;
    while (iteratorNode && iteratorNode->next)
    {
        iteratorNode = iteratorNode->next;
    }
    iteratorNode->next = head;
    head = NodeToBeShifted;
    return head;
}

int main()
{
    return 0;
}