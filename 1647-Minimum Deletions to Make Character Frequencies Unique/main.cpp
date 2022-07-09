#include <bits/stdc++.h>
using namespace std;
int minDeletions(string s)
{
    unordered_set<int> freqSet;
    vector<int> charVector(26, 0);
    int count = 0;
    for (char c : s)
    {
        charVector[c - 'a']++;
    }

    for (int charCount : charVector)
    {
        if (freqSet.find(charCount) == freqSet.end())
        {
            freqSet.insert(charCount);
        }
        else
        {
            while (charCount > 0)
            {
                if (freqSet.find(charCount) == freqSet.end())
                {
                    freqSet.insert(charCount);
                    break;
                }
                else
                {
                    charCount--;
                    count++;
                }
            }
        }
    }
    return count;
}
int main() {}
