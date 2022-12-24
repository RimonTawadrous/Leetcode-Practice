#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // string intToRoman(int num)
    // {
    //     map<int, string> map = {
    //         {1, "I"},
    //         {5, "V"},
    //         {10, "X"},
    //         {50, "L"},
    //         {100, "C"},
    //         {500, "D"},
    //         {1000, "M"},
    //         {4, "IV"},
    //         {9, "IX"},
    //         {40, "XL"},
    //         {90, "XC"},
    //         {400, "CD"},
    //         {900, "CM"},
    //     };
    //     string ans = "";
    //     while (num > 0)
    //     {
    //         auto it = map.upper_bound(num);
    //         num -= (*it).first;
    //         ans += (*it).second;
    //     }
    //     return ans;
    // }

    string intToRoman(int num)
    {
        vector<string> s = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        vector<int> n = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string ans = "";
        while (num > 0)
        {
            for (int i = 0; i < n.size(); i++)
            {
                while (num >= n[i])
                {
                    num -= n[i];
                    ans += s[i];
                }
            }
        }
        return ans;
    }
};

int main()
{
}