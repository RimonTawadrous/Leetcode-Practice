#include <bits/stdc++.h>
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
// ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
// {
//     ListNode *firstListNode = list1;
//     ListNode *secondListNode = list2;
//     ListNode *returnLinkedList;

//     if (!firstListNode)
//     {
//         return list2;
//     }
//     if (!secondListNode)
//     {
//         return list1;
//     }

//     if (firstListNode->val <= secondListNode->val)
//     {
//         returnLinkedList = new ListNode(firstListNode->val);
//         firstListNode = firstListNode->next;
//     }
//     else
//     {
//         returnLinkedList = new ListNode(secondListNode->val);
//         secondListNode = secondListNode->next;
//     }
//         ListNode *curretnReturnLinkedList = returnLinkedList;

//     while (firstListNode != nullptr && secondListNode  != nullptr)
//     {
//         if (firstListNode->val <= secondListNode->val)
//         {
//             cout<< "1 "<<firstListNode->val <<endl;
//             ListNode *newNode =  new ListNode(firstListNode->val); 
//             curretnReturnLinkedList->next = newNode;
//             firstListNode = firstListNode->next;
//         }
//         else{
//             cout<< "2 "<<secondListNode->val <<endl;
//             ListNode *newNode =  new ListNode(secondListNode->val); 
//             curretnReturnLinkedList->next = newNode;
//             secondListNode = secondListNode->next;
//         }
//         curretnReturnLinkedList = curretnReturnLinkedList->next;
//     }

//     while (firstListNode)
//     {
//         ListNode *newNode =  new ListNode(firstListNode->val); 
//         curretnReturnLinkedList->next = newNode;
//         curretnReturnLinkedList = curretnReturnLinkedList->next;
//         firstListNode = firstListNode->next;
//     }

//     while (secondListNode)
//     {
//         ListNode *newNode =  new ListNode(secondListNode->val); 
//         curretnReturnLinkedList->next = newNode;
//         curretnReturnLinkedList = curretnReturnLinkedList->next;
//         secondListNode = secondListNode->next;
//     }
//     return returnLinkedList;
// }


// ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
// {
//     ListNode *firstListNode = list1;
//     ListNode *secondListNode = list2;
//     ListNode *returnLinkedList;

//     if (!firstListNode)
//     {
//         return list2;
//     }
//     if (!secondListNode)
//     {
//         return list1;
//     }

//     if (firstListNode->val <= secondListNode->val)
//     {
//         returnLinkedList = new ListNode(firstListNode->val);
//         firstListNode = firstListNode->next;
//     }
//     else
//     {
//         returnLinkedList = new ListNode(secondListNode->val);
//         secondListNode = secondListNode->next;
//     }
//         ListNode *curretnReturnLinkedList = returnLinkedList;

//     while (firstListNode != nullptr && secondListNode  != nullptr)
//     {
//         if (firstListNode->val <= secondListNode->val)
//         {
//             cout<< "1 "<<firstListNode->val <<endl;
//             curretnReturnLinkedList->next = new ListNode(firstListNode->val); 
//             firstListNode = firstListNode->next;
//         }
//         else{
//             cout<< "2 "<<secondListNode->val <<endl;
//             curretnReturnLinkedList->next = new ListNode(secondListNode->val); 
//             secondListNode = secondListNode->next;
//         }
//         curretnReturnLinkedList = curretnReturnLinkedList->next;
//     }

//     while (firstListNode)
//     {
//         curretnReturnLinkedList->next = new ListNode(firstListNode->val); 
//         curretnReturnLinkedList = curretnReturnLinkedList->next;
//         firstListNode = firstListNode->next;
//     }

//     while (secondListNode)
//     {
//         curretnReturnLinkedList->next = new ListNode(secondListNode->val);
//         curretnReturnLinkedList = curretnReturnLinkedList->next;
//         secondListNode = secondListNode->next;
//     }
//     return returnLinkedList;
// }