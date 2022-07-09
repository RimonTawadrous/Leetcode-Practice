#include <bits/stdc++.h>
using namespace std;

class Trie
{
private:
    struct TrieNode
    {
        char character;
        bool isEnd;
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
    TrieNode *getNode(TrieNode *start, string prefix)
    {
        TrieNode *currentNode = start;
        for (char c : prefix)
        {
            if (currentNode->children.find(c) != currentNode->children.end())
            {
                currentNode = currentNode->children[c];
            }
        }
    }
    vector<string> getTopThree(TrieNode *start, string prefix)
    {
        vector<string> resultsVect;
        resultsVect.reserve(3);
        TrieNode *currentNode = start;

        if (currentNode->isEnd)
        {
            resultsVect.push_back(prefix);
        }

        if (resultsVect.size() == 3)
        {
            return resultsVect;
        }

        for (char c = 'a'; c <= 'z'; c++)
        {
            if (currentNode->children.find(c) != currentNode->children.end())
            {
                if (currentNode->isEnd)
                {
                    resultsVect.push_back(prefix);
                }
                if (resultsVect.size() == 3)
                {
                    return resultsVect;
                }
            }
        }
    }
    ~Trie();
};

// vector<vector<string>> suggestedProducts(vector<string> &products, string searchWord)
// {
//     vector<vector<string>> results;
//     sort(products.begin(), products.end());

//     for (int j = 0; j < products.size(); j++)
//     {
//         cout << products[j] << " ";
//     }
//     cout << endl;

//     int left = 0, right = products.size() - 1;

//     for (int i = 0; i < searchWord.size(); i++)
//     {
//         char c = searchWord[i];
//         while (left <= right && (products[left].size() <= i || products[left][i] != c))
//             left++;
//         while (left <= right && (products[right].size() <= i || products[right][i] != c))
//             right--;

//         int remain = right - left + 1;

//         vector<string> temp;
//         for (int j = left; j < right && j < left + 3; j++)
//         {
//             temp.push_back(products[j]);
//         }
//         results.push_back(temp);
//     }
//     return results;
// }