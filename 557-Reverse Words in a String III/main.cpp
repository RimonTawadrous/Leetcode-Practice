#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        int first = 0, second = 0;
        char temp;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ' ')
            {
                second = i - 1;

                while (first < second)
                {
                    temp = s[first];
                    s[first] = s[second];
                    s[second] = temp;
                    first++;
                    second--;
                }
                first = i + 1;
            }
        }
        second = s.size() - 1;
        while (first < second)
        {
            temp = s[first];
            s[first] = s[second];
            s[second] = temp;
            first++;
            second--;
        }
        return s;
    }
};

int main()
{
}