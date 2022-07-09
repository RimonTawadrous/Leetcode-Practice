#include <bits/stdc++.h>
using namespace std;
#include <stdio.h>

bool isSubsequence(string s, string t)
{
    int ptr1 = 0;
    int ptr2 = 0;

    while (ptr2 < t.size())
    {
        if (s[ptr1] == t[ptr2])
        {
            ptr1++;
            if (ptr1 == s.size())
            {
                return true;
            }
        }
        ptr2++;
    }
    return false;
}
int main()
{
    string s = "abc", t = "ahbgdc";
    cout << isSubsequence(s, t);
    return 0;
}