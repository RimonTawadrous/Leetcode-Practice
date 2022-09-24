#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        vector<int> map(26, 0);
        for (char currentChar : s)
        {
            map[currentChar - 'a']++;
        }

        for (char currentChar : t)
        {
            if (map[currentChar - 'a'] == 0)
            {
                return false;
            }
            map[currentChar - 'a']--;
        }

        for (int num : map)
        {
            if (map[num] > 0)
            {
                return false;
            }
        }

        return true;
    }
};

int main()
{
}