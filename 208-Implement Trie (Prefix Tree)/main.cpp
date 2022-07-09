#include <bits/stdc++.h>
using namespace std;

class Trie
{
private:
    struct TrieNode
    {
        bool isEnd;
        char character;
        map<char, TrieNode *> children;
        TrieNode() : isEnd(false)
        {
        }
        TrieNode(char character) : character(character), isEnd(false)
        {
        }
        void setEnd()
        {
            isEnd = true;
        }
    };
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode();
    }

    void insert(string word)
    {
        TrieNode *currentNode = root;
        for (char c : word)
        {
            if (currentNode->children.find(c) == currentNode->children.end())
            {
                currentNode->children[c] = new TrieNode(c);
            }
            currentNode = currentNode->children[c];
        }
        currentNode->setEnd();
    }

    bool search(string word)
    {
        TrieNode *currentNode = root;
        for (char c : word)
        {
            if (currentNode->children.find(c) != currentNode->children.end())
            {
                currentNode = currentNode->children[c];
            }
            else
            {
                return false;
            }
        }
        return currentNode->isEnd;
    }

    bool startsWith(string prefix)
    {
        TrieNode *currentNode = root;
        for (char c : prefix)
        {
            if (currentNode->children.find(c) != currentNode->children.end())
            {
                currentNode = currentNode->children[c];
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
}
