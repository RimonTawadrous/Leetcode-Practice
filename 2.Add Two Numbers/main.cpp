#include <bits/stdc++.h>
using namespace std;
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    int carry = 0, sum = 0;
    ListNode *firstNumber = l1;
    ListNode *secondNumber = l2;
    ListNode *sumList = NULL;
    ListNode *currentSumNode = NULL;

    while (firstNumber && secondNumber)
    {
        sum = 0;
        sum = firstNumber->val + secondNumber->val + carry;
        carry = sum >= 10 ? 1 : 0;
        sum = sum % 10;
        if (!sumList)
        {
            sumList = new ListNode(sum);
            currentSumNode = sumList;
        }
        else
        {
            currentSumNode->next = new ListNode(sum);
            currentSumNode = currentSumNode->next;
        }
           firstNumber = firstNumber->next;
            secondNumber = secondNumber->next;
    }

    while (firstNumber)
    {
        sum = 0;
        sum = firstNumber->val + carry;
        carry = sum >= 10 ? 1 : 0;
        sum = sum % 10;
        currentSumNode->next = new ListNode(sum);
        currentSumNode = currentSumNode->next;
        firstNumber = firstNumber->next;
    }
    while (secondNumber)
    {
        sum = 0;
        sum = secondNumber->val + carry;
        carry = sum >= 10 ? 1 : 0;
        sum = sum % 10;
        currentSumNode->next = new ListNode(sum);
        currentSumNode = currentSumNode->next;
        secondNumber = secondNumber->next;
    }
    
    if(carry){
         currentSumNode->next = new ListNode(carry);
    }
    return sumList;
}