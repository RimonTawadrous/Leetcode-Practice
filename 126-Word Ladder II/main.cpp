#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        bool endIsNotFound = true;
        bool startIsTooFar = true;
        bool beginIsInWords = false;
        for (int i = 0; i < wordList.size(); i++)
        {
            if (endWord == wordList[i])
            {
                endIsNotFound = false;
            }
            int tempCharDiffCount = charDiffrence(beginWord, wordList[i]);
            if (tempCharDiffCount < 2)
            {
                startIsTooFar = false;
            }
            if (tempCharDiffCount == 0)
            {
                beginIsInWords = true;
            }
        }

        if (endIsNotFound || startIsTooFar)
        {
            return {};
        }

        vector<vector<string>> tempResults;
        unordered_set<string> visited;
        unordered_map<string, unordered_set<string>> map;
        for (int i = 0; i < wordList.size(); i++)
        {
            for (int j = 0; j < wordList.size(); j++)
            {
                if (charDiffrence(wordList[i], wordList[j]) == 1)
                {
                    map[wordList[i]].insert(wordList[j]);
                }
            }
        }

        stack<string> pathStack;
        vector<string> mainVect;

        if (!beginIsInWords)
        {
            for (int i = 0; i < wordList.size(); i++)
            {
                if (charDiffrence(beginWord, wordList[i]) < 2)
                {
                    mainVect.push_back(beginWord);
                    pathStack.push(wordList[i]);
                    visited.insert(wordList[i]);
                    cout << wordList[i] << endl;
                }
            }
        }
        else
        {
            pathStack.push(beginWord);
            visited.insert(beginWord);
        }

        while (!pathStack.empty())
        {
            string tempString = pathStack.top();
            mainVect.push_back(tempString);
            // cout << tempString << endl;

            // cout << "======= " << endl;
            // for (auto t : mainVect)
            // {
            //     cout << t << endl;
            // }
            // cout << "======= " << endl;

            if (map[tempString].find(endWord) != map[tempString].end())
            {
                // cout << "yes" << endl;
                mainVect.push_back(endWord);
                pathStack.push(endWord);
                vector<string> tempResult = mainVect;
                tempResults.push_back(tempResult);

                // cout << tempResults.size() << endl;

                while (!pathStack.empty() && !mainVect.empty())
                {
                    if (pathStack.top() == mainVect.back())
                    {
                        visited.erase(pathStack.top());
                        mainVect.pop_back();
                        pathStack.pop();
                    }
                    else
                    {
                        break;
                    }
                }
            }
            else
            {
                bool foundOne = false;
                for (auto word : map[tempString])
                {
                    // cout << "word1 = " << word << (visited.find(word) == visited.end()) << endl;
                    // for (auto t : visited)
                    // {
                    //     cout << t << endl;
                    // }

                    if (visited.find(word) == visited.end())
                    {
                        foundOne = true;
                        pathStack.push(word);
                        visited.insert(word);
                    }
                }
                if (!foundOne)
                {
                    mainVect.pop_back();
                    pathStack.pop();
                }
            }
        }
        int minLength = INT_MAX;
        vector<vector<string>> Results;

        for (auto ladder : tempResults)
        {
            minLength = minLength > ladder.size() ? ladder.size() : minLength;
        }
        for (auto ladder : tempResults)
        {
            if (ladder.size() == minLength)
            {
                Results.push_back(ladder);
            }
        }

        return Results;
    }

    int charDiffrence(string s1, string s2)
    {
        int diffCount = 0;
        for (int i = 0; i < s1.size(); i++)
        {
            if (s1[i] != s2[i])
            {
                diffCount++;
            }
        }
        return diffCount;
    }
};

int main()
{
    Solution s;
    string beginWord = "hit", endWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
    s.findLadders(beginWord, endWord, wordList);

    cout << s.charDiffrence("tot", "hog");
}
