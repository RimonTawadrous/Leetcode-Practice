#include <bits/stdc++.h>
using namespace std;

// TLE
//  class LRUCache
//  {
//  private:
//      int capacity;
//      unordered_map<int, int> cache;
//      vector<int> keyTimes;
//      int counter;
//      void updateKeyTimes(int key)
//      {
//          if (find(keyTimes.begin(), keyTimes.end(), key) != keyTimes.end())
//          {
//              keyTimes.erase(find(keyTimes.begin(), keyTimes.end(), key));
//          }
//          keyTimes.push_back(key);
//      }

// public:
//     LRUCache(int capacity) : capacity(capacity)
//     {
//     }

//     int get(int key)
//     {
//         if (cache.find(key) != cache.end())
//         {
//             updateKeyTimes(key);
//             return cache[key];
//         }
//         return -1;
//     }

//     void put(int key, int value)
//     {
//         if (cache.find(key) == cache.end() && cache.size() == capacity)
//         {

//             int oldest = keyTimes[0];
//             // remove first element
//             keyTimes.erase(keyTimes.begin());
//             cache.erase(cache.find(oldest));
//         }
//         cache[key] = value;
//         updateKeyTimes(key);
//     }
// };

class LRUCache
{

private:
    struct Node
    {
        int key;
        int value;
        Node *next;
        Node *prev;
        Node() : key(0), value(0), next(nullptr), prev(nullptr) {}
        Node(int key, int value) : key(key), value(value), next(nullptr), prev(nullptr) {}
    };
    Node *head = nullptr, *tail = nullptr;
    int capacity = 0;
    unordered_map<int, Node *> cache;

public:
    LRUCache(int capacity) : capacity(capacity), head(nullptr), tail(nullptr)
    {
        cache.clear();
    }

    int get(int key)
    {
        if (cache.find(key) != cache.end())
        {
            Node *tempNode = cache[key];

            if (tempNode == head)
            {
                return tempNode->value;
            }
            else if (tempNode == tail)
            {
                tail = tail->prev;
                tail->next = nullptr;
            }
            else
            {
                if (tempNode->prev != nullptr)
                {
                    tempNode->prev->next = tempNode->next;
                }
                if (tempNode->next != nullptr)
                {
                    tempNode->next->prev = tempNode->prev;
                }
            }
            tempNode->prev = nullptr;
            head->prev = tempNode;
            tempNode->next = head;
            head = tempNode;
            return tempNode->value;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if (!capacity)
        {
            return;
        }

        if (cache.find(key) != cache.end())
        {
            Node *tempNode = cache[key];
            tempNode->value = value;
            if (tempNode == head)
            {
                return;
            }
            else if (tempNode == tail)
            {
                tail = tail->prev;
                tail->next = nullptr;
            }
            else
            {
                if (tempNode->prev != nullptr)
                {
                    tempNode->prev->next = tempNode->next;
                }
                if (tempNode->next != nullptr)
                {
                    tempNode->next->prev = tempNode->prev;
                }
            }
            tempNode->prev = nullptr;
            head->prev = tempNode;
            tempNode->next = head;
            head = tempNode;
            return;
        }

        Node *newNode = new Node(key, value);
        if (cache.size() == 0)
        {
            cache[key] = newNode;
            head = newNode;
            tail = newNode;
            return;
        }

        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        if (cache.size() == capacity)
        {
            Node *tempNode = tail;
            tail->prev->next = nullptr;
            tail = tail->prev;
            cache.erase(tempNode->key);
            delete tempNode;
        }
        cache[key] = newNode;
    }
};

int main()
{
}