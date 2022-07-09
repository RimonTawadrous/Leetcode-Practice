#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

// with hashmap
Node *copyRandomList(Node *head)
{
    if (!head)
    {
        return NULL;
    }
    unordered_map<Node *, Node *> map;
    Node *currentNode = head;
    Node *newListItNode = nullptr;
    Node *newListHead = nullptr;

    while (currentNode)
    {
        Node *newNode = new Node(currentNode->val);
        if (newListHead == nullptr)
        {
            newListHead = newNode;
            newListItNode = newNode;
        }
        else
        {
            newListItNode->next = newNode;
            newListItNode = newListItNode->next;
        }
        map[currentNode] = newNode;
        currentNode = currentNode->next;
    }
    newListItNode->next = nullptr;
    currentNode = head;
    while (currentNode != nullptr)
    {
        if (map.find(currentNode) != map.end())
        {
            if (currentNode->random != nullptr)
            {
                map[currentNode]->random = map[currentNode->random];
            }
            else
            {
                map[currentNode]->random = nullptr;
            }
        }
        currentNode = currentNode->next;
    }
    return newListHead;
}

//o(n) , space: O(1)
Node *copyRandomList(Node *head)
{
    if (!head)
    {
        return NULL;
    }
    Node *currentNode = head;
    Node *newHead;
    Node *tempNode;
    while (currentNode)
    {
        Node *newNode = new Node(currentNode->val);
        tempNode = currentNode->next;
        currentNode->next = newNode;
        newNode->next = tempNode;
        currentNode = tempNode;
    }
    currentNode = head;
    while (currentNode)
    {
        if (currentNode->random)
        {
            currentNode->next->random = currentNode->random->next;
        }
        else
        {
            currentNode->next->random = NULL;
        }
        currentNode = currentNode->next->next;
    }
    currentNode = head;
    newHead = currentNode->next;
    while (currentNode)
    {
        tempNode = currentNode->next->next;
        if (currentNode->next->next)
        {
            currentNode->next->next = currentNode->next->next->next;
        }
        else
        {
            currentNode->next->next = NULL;
        }

        currentNode->next = tempNode;
        currentNode = tempNode;
    }

    return newHead;
}

int main()
{
}