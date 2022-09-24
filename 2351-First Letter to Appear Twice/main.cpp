#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int repeatedCharacter(string s)
    {
        vector<int> chars(26, 0);

        for (int i = 0; i < s.size(); i++)
        {
            chars[s[i] - 'a']++;
            if (chars[s[i] - 'a'] == 2)
            {
                return s[i];
            }
        }
        return -1;
    }
};
