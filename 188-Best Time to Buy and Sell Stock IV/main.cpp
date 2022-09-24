#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfit(int k, vector<int> &prices)
    {
        if (prices.empty())
        {
            return 0;
        }
        vector<int> dp(prices.size(), 0);
        for (int i = 0; i < k; i++)
        {
            int pos = -prices[0], profite = 0;
            for (int j = 1; j < prices.size(); j++)
            {
                pos = max(pos, dp[j] - prices[j]);
                profite = max(profite, pos + prices[j]);
                dp[j] = profite;
            }
        }
        return dp[dp.size() - 1];
    }
};

int main()
{
}