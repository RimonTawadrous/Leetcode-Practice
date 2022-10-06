#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        vector<int> map(26, -1);

        for (char currentChar : magazine)
        {
            map[currentChar - 'a']++;
        }

        for (char currentChar : ransomNote)
        {
            if (map[currentChar - 'a'] < 0)
            {
                return false;
            }
            map[currentChar - 'a']--;
        }
        return true;
    }
};

int main()
{
}