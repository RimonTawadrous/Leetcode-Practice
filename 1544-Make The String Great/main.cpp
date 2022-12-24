#include <bits/stdc++.h>
using namespace std;

// better solution
class Solution
{
public:
    string makeGood(string s)
    {
        string ans;
        for (char c : s)
        {
            ans.push_back(c);
            while (ans.size() > 1 && abs(ans[ans.size() - 2] - ans[ans.size() - 1]) == 32)
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