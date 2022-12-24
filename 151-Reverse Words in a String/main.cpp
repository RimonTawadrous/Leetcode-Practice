#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // string reverseWords(string s)
    // {

    //     while (s[s.size() - 1] == ' ')
    //     {
    //         s.pop_back();
    //     }

    //     int stopAtFrontIndex = 0;
    //     while (stopAtFrontIndex < s.size() && s[stopAtFrontIndex] == ' ')
    //     {
    //         stopAtFrontIndex++;
    //     }

    //     int index = s.size() - 1;

    //     while (index >= stopAtFrontIndex && s[index] != ' ')
    //     {
    //         index--;
    //     }
    //     string temp;
    //     while (index >= stopAtFrontIndex)
    //     {
    //         while()
    //         s.push_back(s[index]);
    //         index--;
    //     }
    //     return s;
    // }

    string reverseWords(string s)
    {
        vector<string> words;
        string temp;
        int index = 0;
        while (index < s.size())
        {
            while (index < s.size() && s[index] == ' ')
            {
                index++;
            }
            temp = "";
            while (index < s.size() && s[index] != ' ')
            {
                temp += s[index];
                index++;
            }
            if (temp != "")
            {
                words.push_back(temp);
            }
        }
        string ans = "";
        for (int i = words.size() - 1; i > -1; i--)
        {
            ans += words[i] + " ";
        }
        ans.pop_back();
        return ans;
    }
};

int main()
{
    Solution s;
    cout << s.reverseWords("the sky is blue") << endl;
}