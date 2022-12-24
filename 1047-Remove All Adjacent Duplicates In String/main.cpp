#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string removeDuplicates(string s)
    {
        stack<char> charStack;
        for (char ch : s)
        {
            bool removed = false;
            while (!charStack.empty() && charStack.top() == ch)
            {
                charStack.pop();
                removed = true;
            }
            if (!removed)
            {
                charStack.push(ch);
            }
        }
        string ans;
        while (!charStack.empty())
        {
            ans += charStack.top();
            charStack.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

// better solution
class Solution
{
public:
    string removeDuplicates(string s)
    {
        string ans;
        for (char ch : s)
        {
            ans.push_back(ch);
            while (ans.size() > 1 && ans[ans.size() - 2] == ans[ans.size() - 1])
            {
                ans.pop_back();
                ans.pop_back();
            }
        }
        return ans;
    }
};

int main()
{
}