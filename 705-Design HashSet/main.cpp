#include <bits/stdc++.h>
using namespace std;

class MyHashSet
{
    size_t LIST_SIZE = 15000;
    vector<vector<int>> map;

    int hash_function(int key)
    {
        return key % LIST_SIZE;
    }

public:
    MyHashSet()
    {
        map = vector<vector<int>>(LIST_SIZE, vector<int>{});
    }

    void add(int key)
    {
        int hash = hash_function(key);
        if (!this->contains(key))
        {
            map[hash].push_back(key);
        }
    }

    void remove(int key)
    {
        int hash = hash_function(key);
        vector<int>::iterator it =  find(map[hash].begin(), map[hash].end(), key);
        if (it != map[hash].end())
        {
            map[hash].erase(it);
        }
    }

    bool contains(int key)
    {
        int hash = hash_function(key);
        return !(find(map[hash].begin(), map[hash].end(), key) == map[hash].end());
    }
};

int main()
{
}