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

class Solution
{
public:
    // //  2 itrations approach
    // ListNode *deleteMiddle(ListNode *head)
    // {
    //     int linkedListLength = 0;
    //     ListNode *currentNode = head;
    //     while (currentNode)
    //     {
    //         currentNode = currentNode->next;
    //         linkedListLength++;
    //     }
    //     currentNode = head;
    //     if (linkedListLength == 1)
    //     {
    //         delete head;
    //         return NULL;
    //     }
    //     int mid = linkedListLength / 2;
    //     while ((mid - 1) > 0)
    //     {
    //         currentNode = currentNode->next;
    //         mid--;
    //     }
    //     ListNode *nodeToDelete = currentNode->next;
    //     currentNode->next = nodeToDelete->next;
    //     delete nodeToDelete;
    //     return head;
    // }

    ListNode *deleteMiddle(ListNode *head)
    {
        ListNode *fastIt = head;
        ListNode *slowIt = head;
        ListNode *prevIt = head;
        if (!head)
        {
            return head;
        }
        if (!head->next)
        {
            delete head;
            return NULL;
        }

        while (fastIt && fastIt->next)
        {
            fastIt = fastIt->next->next;
            prevIt = slowIt;
            slowIt = slowIt->next;
        }
        prevIt->next = slowIt->next;
        delete slowIt;
        return head;
    }
};

int main()
{
}