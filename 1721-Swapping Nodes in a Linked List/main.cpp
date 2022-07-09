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
    ListNode *swapNodes(ListNode *head, int k)
    {
        ListNode *currentNode = head;
        ListNode *firstNode, *secondNode;
        int size = 0, firstIndex, lastIndex;
        if (!currentNode)
        {
            return head;
        }
        while (currentNode)
        {
            size++;
            currentNode = currentNode->next;
        }

        if (size == 1)
        {
            return head;
        }
        currentNode = head;
        lastIndex = size - k;
        firstIndex = k - 1;
        while (currentNode)
        {
            if (firstIndex == 0)
            {
                cout << "first Index = " << firstIndex << " value = " << currentNode->val << endl;
                firstNode = currentNode;
            }
            if (lastIndex == 0)
            {
                cout << "lastIndex = " << lastIndex << " value = " << currentNode->val << endl;
                secondNode = currentNode;
            }
            firstIndex--;
            lastIndex--;
            currentNode = currentNode->next;
        }

        if (firstNode == secondNode)
        {
            return head;
        }
        int temp = firstNode->val;
        firstNode->val = secondNode->val;
        secondNode->val = temp;
        return head;
    }
};

int main()
{
}