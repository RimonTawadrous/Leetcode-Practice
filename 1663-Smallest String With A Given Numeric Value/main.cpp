#include <bits/stdc++.h>
using namespace std;

string getSmallestString(int n, int k)
{
    if (n == 0 || k == 0)
    {
        return "";
    }

    vector<char> charMap(26);
    for (size_t i = 97; i < 123; i++)
    {
        charMap[i - 97] = (char)i;
    }

    int digitsNum = n;
    int value = k - digitsNum;
    int i = n-1;
    string s (n,'ش');
    while (i > -1)
    {
        if (value >= 26)
        {
            s[i] = charMap[25];
            value = (value + 1) - 26;
        }
        else
        {
            s[i] = charMap[value];
            value = 0;
        }
        i--;
    }
    return s;
}

int main()
{
    cout << getSmallestString(3, 27) << endl;
    return 0;
}