#include <bits/stdc++.h>
using namespace std;

string longestPalindrome(string s)
{
    int n = s.size() + 1;
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (s[i - 1] == s[n - j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return "";
}

int main()
{
    longestPalindrome("babad");
}