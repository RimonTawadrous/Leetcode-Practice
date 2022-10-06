
// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
class Solution
{
public:
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        if (left == right)
        {
            return head;
        }
        ListNode *currentNode = head, *beforeLeft = nullptr, *afterRight, *firstNodePrev, *firstNode = nullptr, *lefthead = nullptr, *tempNode;
        int currentNumber = 1;

        while (currentNumber < left && currentNode != nullptr)
        {

            if (beforeLeft == nullptr)
            {
                beforeLeft = head;
            }
            else
            {
                beforeLeft = beforeLeft->next;
            }
            currentNode = currentNode->next;
            currentNumber++;
        }

        if (beforeLeft == nullptr)
        {
            firstNodePrev = head;
            firstNode = head->next;
            lefthead = head;
        }
        else
        {
            firstNodePrev = beforeLeft->next;
            firstNode = firstNodePrev->next;
            lefthead = beforeLeft->next;
        }

        while (currentNumber < right)
        {
            tempNode = firstNode->next;
            firstNode->next = firstNodePrev;
            firstNodePrev = firstNode;
            firstNode = tempNode;
            currentNumber++;
        }

        if (beforeLeft == nullptr)
        {
            head = firstNodePrev;
        }
        else
        {
            beforeLeft->next = firstNodePrev;
        }

        if (tempNode == nullptr)
        {
            lefthead->next = nullptr;
        }
        else
        {
            lefthead->next = tempNode;
        }
        return head;
    }
};

int main()
{
}