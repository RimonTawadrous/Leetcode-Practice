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
    ListNode *partition(ListNode *head, int x)
    {
        if (head == nullptr)
        {
            return head;
        }
        ListNode *lessNode = nullptr, *currentNode = head, *tempNode;
        while (currentNode != nullptr && currentNode->next != nullptr)
        {
            if (currentNode == head)
            {
                if (currentNode->val < x)
                {
                    lessNode = currentNode;
                }
            }
            if (currentNode->next->val < x)
            {
                if (lessNode == nullptr)
                {
                    tempNode = currentNode->next;
                    currentNode->next = currentNode->next->next;
                    tempNode->next = head;
                    head = tempNode;
                    lessNode = tempNode;
                }
                else if (lessNode->next == currentNode->next)
                {
                    currentNode = currentNode->next;
                    lessNode = lessNode->next;
                }
                else
                {
                    tempNode = currentNode->next;
                    currentNode->next = currentNode->next->next;
                    tempNode->next = lessNode->next;
                    lessNode->next = tempNode;
                    lessNode = tempNode;
                }
            }
            else if (currentNode->next->val >= x)
            {
                currentNode = currentNode->next;
            }
        }

        return head;
    }
};

int main() {}