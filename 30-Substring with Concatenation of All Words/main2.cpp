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
                        start = start + 1;
                        tempStr = "";
                        i = start;
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
                        // cout << tempStr << endl;
                    }
                    if (remainingWords == 0)
                    {
                        // cout << "found = " << start << endl;
                        ans.push_back(start);
                        remainingWords = words.size();
                        start = start + 1;
                        i = start;
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
                    tempStr = tempStr.substr(1);
                    remainingWords = words.size();
                    start = i - wordSize + 2;
                    cout << tempStr << endl;
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

        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << endl;
        }

        return ans;
    }
};

int main()
{
    Solution s;

    // vector<string> words = {"word", "good", "best", "good"};
    // s.findSubstring("wordgoodgoodgoodbestword", words);

    // vector<string> words = {
    //     "bar",
    //     "foo",
    //     "the",
    // };
    // s.findSubstring("barfoofoobarthefoobarman", words);

    vector<string> words = {"aa", "aa"};
    s.findSubstring("aaaaaaaaaaaaaa", words);
}
