#include <bits/stdc++.h>
using namespace std;

int coinChange(vector<int> &coins, int amount)
{
    if (amount == 0)
    {
        return 0;
    }
    int total = amount + 1;
    vector<vector<int>> dp(coins.size(), vector<int>(total, -1));
    sort(coins.begin(), coins.end());

    for (size_t i = 0; i < coins.size(); i++)
    {

        if (coins[i] < total)
        {
            if (i > 0)
            {
                for (size_t j = 0; j < coins[i]; j++)
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }

            cout << "coins = " << coins[i] << endl;
            dp[i][coins[i]] = 1;
            for (size_t j = coins[i] + 1; j < total; j++)
            {
                if (i > 0)
                {
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - coins[i]] + 1);
                }
                else
                {
                    dp[i][j] = dp[i][j - coins[i]] + 1;
                    cout << "dp[i][j - coins[i]] + 1 = " << dp[i][j - coins[i]] << "" << endl;
                }
            }
        }
        else
        {
            cout << "else coins = " << coins[i] << endl;
            if (i > 0)
            {
                cout << "return  dp[i - 1][amount]" << endl;
                return dp[i - 1][amount];
            }
            else
            {
                cout << "return -1" << endl;
                return -1;
            }
            break;
        }
    }
    return dp[coins.size() - 1][amount] ? dp[coins.size() - 1][amount] : -1;
}

int main()
{
    // vector<int> test = {1, 2, 3};
    // vector<int> test = {1, 2147483647};
    vector<int> test = {1};

    cout << coinChange(test, 1);
}