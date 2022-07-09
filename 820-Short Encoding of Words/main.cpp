#include <bits/stdc++.h>
using namespace std;

class Trie
{
private:
    struct TrieNode
    {
        bool isEnd;
        int length;
        map<char, TrieNode *> children;
        char character;
        TrieNode() : isEnd(false)
        {
        }
        TrieNode(char character) : character(character), isEnd(false)
        {
        }
    };
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode();
    }
    int insert(string word)
    {
        TrieNode *currentNode = root;
        int count = 0;
        int number = 0;
        bool append = false;
        for (size_t i = 0; i < word.size(); i++)
        {
            char c = word[i];
            if (currentNode->children.find(c) == currentNode->children.end())
            {
                currentNode->children[c] = new TrieNode(c);
                count++;
                currentNode = currentNode->children[c];
            }
            else
            {
                number++;
                currentNode = currentNode->children[c];
                if (!currentNode->isEnd)
                {
                    cout << "no = " << c << endl;
                    count = number;
                }
                else if (currentNode->isEnd)
                {
                    cout << "yes " << c << endl;
                    currentNode->isEnd = false;
                    append = true;
                }
            }
        }
        currentNode->isEnd = true;
        cout << "currentNode = " << currentNode->isEnd << "  " << currentNode->character << endl;

        return append ? (count) : (count);
    }

    ~Trie()
    {
    }
};

int minimumLengthEncoding(vector<string> &words)
{
    Trie *trie = new Trie();
    int size = 0;
    for (string word : words)
    {
        string temp = word;
        reverse(temp.begin(), temp.end());
        size += trie->insert(temp);
    }
    return size;
}

// int minimumLengthEncoding(vector<string> &words)
// {
//     set<string> wordsSet;
//     int size = 0;
//     for (string word : words)
//     {
//         wordsSet.insert(word);
//     }

//     for (string word : words)
//     {
//         for (size_t i = 1; i < word.size(); i++)
//         {
//             string sub = word.substr(i, (word.size() - i));
//             if (wordsSet.find(sub) != wordsSet.end())
//             {
//                 wordsSet.erase(sub);
//             }
//         }
//     }

//     for (string word : wordsSet)
//     {
//         size += word.size() + 1;
//     }
//     return size;
// }

int main()
{
    // vector<string> words = {"time", "me", "bell", "frame"};
    // vector<string> words = {"me", "time"};

    cout << minimumLengthEncoding(words) << endl;
}