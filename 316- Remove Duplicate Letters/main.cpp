#include <bits/stdc++.h>
using namespace std;

string removeDuplicateLetters(string s)
{
    if (!s.size())
    {
        return s;
    }
    unordered_map<char, int> charLastSeen;
    stack<char> charStack;
    for (size_t i = 0; i < s.size(); i++)
    {
        charLastSeen[s[i]] = i;
    }
    unordered_map<char, int> charSeenFlags(charLastSeen.size());
    for (size_t i = 0; i < s.size(); i++)
    {
        if (charSeenFlags[s[i]])
        {
            continue;
        }
        else
        {
            while (!charStack.empty() && charStack.top() > s[i] && charLastSeen[charStack.top()] > i)
            {
                charSeenFlags[charStack.top()] = false;
                charStack.pop();
            }
            charStack.push(s[i]);
        }
        charSeenFlags[s[i]] = true;
    }
    string res = "";
    while (!charStack.empty())
    {
        res.push_back(charStack.top());
        charStack.pop();
    }
    reverse(res.begin(), res.end());
    return res;
}

int main()
{
    cout << removeDuplicateLetters("cbacdcbc") << endl;
}