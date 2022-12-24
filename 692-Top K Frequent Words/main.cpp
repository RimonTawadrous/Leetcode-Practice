#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    struct comp
    {
        bool operator()(const pair<int, string> x1, const pair<int, string> x2)
        {
            return x1.first > x2.first || (x1.first == x2.first && x1.second < x2.second);
        }
    };

public:
    // vector<string> topKFrequent(vector<string> &words, int k)
    // {

    //     unordered_map<string, int> wordsFreq;
    //     unordered_set<string> includedWord;
    //     for (string word : words)
    //     {
    //         wordsFreq[word]++;
    //     }
    //     vector<pair<int, string>> total;
    //     vector<string> ans;

    //     for (string word : words)
    //     {
    //         if (includedWord.find(word) == includedWord.end())
    //         {
    //             total.push_back(make_pair(wordsFreq[word], word));
    //             includedWord.insert(word);
    //         }
    //     }

    //     sort(total.begin(), total.end(), comp());

    //     for (int i = 0; i < k && i < total.size(); i++)
    //     {
    //         ans.push_back(total[i].second);
    //     }

    //     return ans;
    // }

    vector<string> topKFrequent(vector<string> &words, int k)
    {

        unordered_map<string, int> wordsFreq;
        unordered_map<string, int> includedWord;
        priority_queue<pair<int, string>, vector<pair<int, string>>, comp> heap;

        for (string word : words)
        {
            wordsFreq[word]++;
            if (heap.empty())
            {
                heap.push(make_pair(wordsFreq[word], word));
            }
            else if (heap.top().first < wordsFreq[word])
            {
                heap.pop();
                heap.push(make_pair(wordsFreq[word], word));
            }
        }
        vector<string> ans;

        for (string word : words)
        {
            if (wordsFreq[word] == k && includedWord.find(word) == includedWord.end())
            {
                ans.push_back(word);
                includedWord.insert(word);
            }
        }
        return ans;
    }
};

int main()
{
}