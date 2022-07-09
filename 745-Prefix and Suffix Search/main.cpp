#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

class Trie
{
private:
    struct TrieNode
    {
        set<int> indexes;
        char character;
        map<char, TrieNode *> children;
        TrieNode()
        {
        }
        TrieNode(char character) : character(character)
        {
        }
    };
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode();
    }

    void insert(string word, int index)
    {
        TrieNode *currentNode = root;
        for (char c : word)
        {
            if (currentNode->children.find(c) == currentNode->children.end())
            {
                currentNode->children[c] = new TrieNode(c);
            }
            currentNode->indexes.insert(index);
            currentNode = currentNode->children[c];
        }
    }

    set<int> startsWith(string prefix)
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
                return set<int>();
            }
        }
        return currentNode->indexes;
    }
};

class WordFilter
{
private:
    Trie *prefexTrie;
    Trie *suffixTrie;

public:
    WordFilter(vector<string> &words)
    {
        prefexTrie = new Trie();
        suffixTrie = new Trie();

        for (size_t i = 0; i < words.size(); i++)
        {
            prefexTrie->insert(words[i], i);
            reverse(words[i].begin(), words[i].end());
            suffixTrie->insert(words[i], i);
        }
    }

    int f(string prefix, string suffix)
    {
        reverse(suffix.begin(), suffix.end());
        set<int> pSet = prefexTrie->startsWith(prefix);
        set<int> sSet = suffixTrie->startsWith(suffix);

        for (int val : sSet)
        {
            if (pSet.find(val) != pSet.end())
            {
                return val;
            }
        }
        return -1;
    }
};

int main()
{
    vector<string> test = {"apple"};
    WordFilter wordFilter(test);
    cout << "ans =  " << wordFilter.f("a", "e") << endl;
}
