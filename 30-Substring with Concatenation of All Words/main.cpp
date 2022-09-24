#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findSubstring(string s, vector<string> &words)
    {
        unordered_map<string, int> freq, tempFreq;
        string tempStr;
        int wordSize = words[0].size(), remainingWords = words.size(), start = 0;
        bool isChanged = false;
        vector<int> ans;
        for (string word : words)
        {
            freq[word]++;
        }
        for (auto &it : freq)
        {
            tempFreq[it.first] = it.second;
        }

        for (int i = 0; i < s.size(); i++)
        {
            tempStr += s[i];
            if (tempStr.size() >= wordSize)
            {
                if (tempFreq.find(tempStr) != tempFreq.end())
                {
                    if (tempFreq[tempStr] == 0)
                    {
                        remainingWords = words.size();
                        i = start;
                        start = start + 1;
                        tempStr = "";
                        for (auto &it : freq)
                        {
                            tempFreq[it.first] = it.second;
                        }
                        isChanged = false;
                    }
                    else
                    {
                        tempFreq[tempStr]--;
                        remainingWords--;
                        isChanged = true;
                    }
                    if (remainingWords == 0)
                    {
                        ans.push_back(start);
                        remainingWords = words.size();
                        i = start;
                        start = start + 1;
                        for (auto &it : freq)
                        {
                            tempFreq[it.first] = it.second;
                        }
                        isChanged = false;
                    }
                    tempStr = "";
                }
                else
                {
                    remainingWords = words.size();
                    i = start;
                    start = start + 1;
                    tempStr = "";
                    if (isChanged)
                    {
                        for (auto &it : freq)
                        {
                            tempFreq[it.first] = it.second;
                        }
                        isChanged = false;
                    }
                }
            }
        }

        return ans;
    }
};

int main()
{
    Solution s;

    vector<string> words = {"word", "good", "best", "good"};
    s.findSubstring("wordgoodgoodgoodbestword", words);

    // vector<string> words = {
    //     "bar",
    //     "foo",
    //     "the",
    // };
    // s.findSubstring("barfoofoobarthefoobarman", words);

    // vector<string> words = {"a", "a"};
    // s.findSubstring("aaa", words);

    // vector<string> words = {"aa", "aa"};
    // s.findSubstring("aaaaaaaaaaaaaa", words);

    // vector<string> words = {"ab", "ba", "ab", "ba"};
    // s.findSubstring("abaababbaba", words);
}