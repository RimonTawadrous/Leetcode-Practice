#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int maxCount = 0;

public:
    int maxLength(vector<string> &arr)
    {
        dfs(0, "", arr);
        return maxCount;
    }

    void dfs(int index, string s, vector<string> &arr)
    {
        maxCount = max(maxCount, (int)s.size());
        for (int i = index; i < arr.size(); i++)
        {
            if (hasUniqueCharacters(s, arr[i]))
            {
                dfs(i + 1, s + arr[i], arr);
            }
        }
    }

    bool hasUniqueCharacters(string s1, string s2)
    {
        vector<bool> chars(26, false);
        for (char currentChar : s1)
        {
            if (chars[currentChar - 'a'])
            {
                return false;
            }
            chars[currentChar - 'a'] = true;
        }

        for (char currentChar : s2)
        {
            if (chars[currentChar - 'a'])
            {
                return false;
            }
            chars[currentChar - 'a'] = true;
        }
        return true;
    }
};

int main()
{
}