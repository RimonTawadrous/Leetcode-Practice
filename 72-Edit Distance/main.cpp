#include <bits/stdc++.h>
using namespace std;

int minDistance(string word1, string word2)
{
    vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));

    for (size_t i = 0; i < dp.size(); i++)
    {
        for (size_t j = 0; j < dp[i].size(); j++)
        {
            if (i == 0)
            {
                dp[i][j] = j;
                continue;
            }
            else if (j == 0)
            {
                dp[i][j] = i;
                continue;
            }

            if (word1[i - 1] == word2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = min(dp[i - 1][j - 1] + 1, min(dp[i - 1][j] + 1, dp[i][j - 1] + 1));
            }
        }
    }

    return dp[word1.size()][word2.size()];
}

int main()
{
    cout << minDistance("intention", "execution");
}