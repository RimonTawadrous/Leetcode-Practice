#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int romanToInt(string s)
    {
        unordered_map<char, int> map;
        map['I'] = 1;
        map['V'] = 5;
        map['X'] = 10;
        map['L'] = 50;
        map['C'] = 100;
        map['D'] = 500;
        map['M'] = 1000;
        int count = 0, prev = map[s[0]];

        for (int i = 0; i < s.size(); i++)
        {
            if (prev < map[s[i]])
            {
                count += map[s[i]] - (prev * 2);
                prev = map[s[i]];
                continue;
            }
            count += map[s[i]];
            prev = map[s[i]];
        }
        return count;
    }
};