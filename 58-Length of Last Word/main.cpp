#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        if (s.empty())
        {
            return 0;
        }
        int size = 0, i = s.size() - 1;
        while (s[i] == ' ' && i > -1)
        {
            i--;
        }
        for (i; i > -1; i--)
        {
            if (s[i] == ' ')
            {
                break;
            }
            size++;
        }
        return size;
    }
};
int main()
{

    return 0;
}