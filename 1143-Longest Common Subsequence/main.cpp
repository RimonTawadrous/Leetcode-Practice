#include <bits/stdc++.h>
using namespace std;

int longestCommonSubsequence(string text1, string text2)
{
    vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));

    for (size_t i = 1; i < dp.size(); i++)
    {
        for (size_t j = 1; j < dp[i].size(); j++)
        {

            if (text1[i - 1] == text2[j - 1])
            {
                cout << "yes\n";
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[text1.size()][text2.size()];
}

int main()
{
    cout << longestCommonSubsequence("ABC", "DEF") << endl;
}