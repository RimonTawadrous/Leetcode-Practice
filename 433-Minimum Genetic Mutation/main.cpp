#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    string end;

public:
    int minMutation(string start, string end, vector<string> &bank)
    {
        unordered_map<string, int> bankStringsCharDiffenceCountFromEnd;
        unordered_map<string, int> bankStringsCharDiffenceCountFromStart;
        unordered_set<string> visitedGens;
        string startStr = start;
        int count = 0;
        for (string s : bank)
        {
            bankStringsCharDiffenceCountFromEnd[s] = charDiffrenceBetweenStrings(s, end);
        }

        while (startStr != end)
        {
            string chosenStr = "";
            int diffFromEnd = INT_MAX;

            for (string s : bank)
            {
                if (charDiffrenceBetweenStrings(startStr, s) == 1)
                {
                    if (diffFromEnd > bankStringsCharDiffenceCountFromEnd[s] && visitedGens.find(s) == visitedGens.end())
                    {
                        diffFromEnd = bankStringsCharDiffenceCountFromEnd[s];
                        chosenStr = s;
                    }
                }
            }
            if (chosenStr == "")
            {
                return -1;
            }
            visitedGens.insert(chosenStr);
            startStr = chosenStr;
            count++;
        }

        return count;
    }

    int charDiffrenceBetweenStrings(string s1, string s2)
    {
        int charDiffCount = 0;
        for (int i = 0; i < s1.size(); i++)
        {
            if (s1[i] != s2[i])
            {
                charDiffCount++;
            }
        }
        return charDiffCount;
    }

    bool isEnd(string s)
    {
        return s == end;
    }
};

int main()
{
}