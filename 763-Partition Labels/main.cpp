#include <bits/stdc++.h>
using namespace std;

vector<int> partitionLabels(string s)
{
    unordered_map<char, int> charLastIndex;
    vector<int> output;
    int size = 0;
    int end = 0;
    for (size_t i = 0; i < s.size(); i++)
    {
        charLastIndex[s[i]] = i;
    }

    for (size_t i = 0; i < s.size(); i++)
    {
        end = max(end, charLastIndex[s[i]]);
        size++;
        if(i == end){
            output.push_back(size);
            size = 0;
        }
    }
    return output;
}

int main()
{
}