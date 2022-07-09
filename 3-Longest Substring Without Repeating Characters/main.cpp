#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s)
{
    map<char, int> charMap;
    int maxLength = 0, firstIndex = 0;

    for (size_t i = 0; i < s.size(); i++)
    {
        if (charMap.find(s[i]) != charMap.end())
        {
            firstIndex = max(firstIndex, charMap[s[i]] + 1);
        }
        charMap[s[i]] = i;
        maxLength = max(maxLength, (int)(i - firstIndex + 1));
    }
    return maxLength;
}

int main()
{
    string s = " ";
    cout << lengthOfLongestSubstring(s) << endl;
}