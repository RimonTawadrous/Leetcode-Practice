#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string defangIPaddr(string address)
    {
        string result;
        for (auto character : address)
        {
            if (character == '.')
            {
                result += "[.]";
            }
            else
            {
                result += character;
            }
        }
        return result;
    }
};