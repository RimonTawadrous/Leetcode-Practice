#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        if (s.size() == 0)
        {
            return true;
        }
        int sPtr = 0;
        for (int i = 0; i < t.size(); i++)
        {
            if (s[sPtr] == t[i])
            {
                sPtr++;
                if (sPtr == s.size())
                {
                    return true;
                }
            }
        }
        return false;
    }
};

int main()
{

    return 0;
}