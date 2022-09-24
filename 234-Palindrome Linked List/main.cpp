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
    bool isPalindrome(ListNode *head)
    {
        if (head == nullptr)
        {
            return true;
        }
        int count = 0, startComparing = 0, indexCount = 0;
        bool hasMiddle = false;
        ListNode *currentNode = head;

        while (currentNode != nullptr)
        {
            count++;
            currentNode = currentNode->next;
        }
        if (count == 1)
        {
            return true;
        }

        if (count % 2 == 0)
        {
            startComparing = (count / 2);
        }
        else
        {
            startComparing = (count / 2) + 1;
            hasMiddle = true;
        }
        currentNode = head;
        stack<int> staq;
        while (currentNode != nullptr)
        {
            if (indexCount < startComparing)
            {
                indexCount++;
                staq.push(currentNode->val);
                currentNode = currentNode->next;
                if (indexCount == startComparing - 1 && hasMiddle)
                {
                    indexCount++;
                    currentNode = currentNode->next;
                }
            }
            else
            {
                if (staq.top() != currentNode->val)
                {
                    return false;
                }

                staq.pop();
                currentNode = currentNode->next;
            }
        }
        return true;
    }
};

// // complexity o(3N) some times gives TLE
// class Solution
// {
// public:
//     bool isPalindrome(ListNode *head)
//     {
//         if (head == nullptr)
//         {
//             return true;
//         }
//         int count = 0, startComparing = 0, indexCount = 0;
//         bool result = true;
//         ListNode *currentNode = head, *prev, *tail, *currentNodeRev;
//         ListNode *tempNode, *tempPrev;
//         while (currentNode->next != nullptr)
//         {
//             count++;
//             currentNode = currentNode->next;
//         }
//         count++;
//         tail = currentNode;
//         if (count % 2 == 0)
//         {
//             startComparing = (count / 2);
//         }
//         else
//         {
//             startComparing = (count / 2) + 1;
//         }
//         currentNode = head;
//         while (currentNode != nullptr)
//         {
//             if (indexCount < startComparing)
//             {
//                 indexCount++;
//                 prev = currentNode;
//                 currentNode = currentNode->next;
//             }
//             else
//             {
//                 tempPrev = prev;
//                 tempNode = currentNode;
//                 prev = currentNode;
//                 currentNode = currentNode->next;
//                 tempNode->next = tempPrev;
//             }
//         }
//         currentNode = head;
//         currentNodeRev = tail;
//         indexCount = startComparing;
//         while (indexCount > 0)
//         {
//             if (currentNode->val != currentNodeRev->val)
//             {
//                 result = false;
//                 break;
//             }

//             if (currentNode->next == currentNodeRev->next)
//             {
//                 break;
//             }
//             indexCount--;
//             currentNode = currentNode->next;
//             currentNodeRev = currentNodeRev->next;
//         }

//         prev = tail;
//         currentNodeRev = tail->next;
//         indexCount = count - startComparing;

//         while (indexCount > 0)
//         {
//             cout << prev->val << endl;
//             cout << currentNodeRev->val << endl;

//             indexCount--;
//             tempPrev = prev;
//             tempNode = currentNodeRev;
//             prev = currentNodeRev;
//             currentNodeRev = currentNodeRev->next;
//             tempNode->next = tempPrev;
//         }

//         tail->next = nullptr;

//         return result;
//     }
// };

int main()
{
}