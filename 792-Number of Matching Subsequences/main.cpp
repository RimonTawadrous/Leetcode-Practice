#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numMatchingSubseq(string s, vector<string> &words)
    {
        unordered_map<string, int> wordsFreqMap;
        unordered_map<string, bool> visitedWords;

        for (string word : words)
        {
            if (wordsFreqMap.find(word) == wordsFreqMap.end())
            {
                wordsFreqMap[word] = 1;
            }
            else
            {
                wordsFreqMap[word]++;
            }
        }
        int wordIndex = 0;
        int sIndex = 0;
        int count = 0;
        for (string word : words)
        {
            wordIndex = 0;
            sIndex = 0;
            if (visitedWords.find(word) != visitedWords.end())
            {
                continue;
            }
            visitedWords[word] = true;
            while (sIndex < s.size() && wordIndex < word.size())
            {
                if (s[sIndex] == word[wordIndex])
                {
                    sIndex++;
                    wordIndex++;
                }
                else
                {
                    sIndex++;
                }
            }
            if (wordIndex == word.size())
            {
                if (wordsFreqMap.find(word) != wordsFreqMap.end())
                {
                    count += wordsFreqMap[word];
                }
                else
                {
                    count++;
                }
            }
        }
        return count;
    }
};
int main()
{
}