#include <bits/stdc++.h>
using namespace std;

// time: O(n), space:O(n)
int minCostClimbingStairs(vector<int> &cost)
{

    if (cost.size() == 0)
    {
        return 0;
    }
    else if (cost.size() == 1)
    {
        return cost[0];
    }

    vector<int> dp(cost.size() + 1, INT_MAX);
    cost.push_back(0);
    dp[0] = cost[0];
    dp[1] = cost[1];
    for (int i = 2; i < cost.size(); i++)
    {
        dp[i] = min(dp[i - 1] + cost[i], dp[i - 2] + cost[i]);
    }
    return dp[dp.size() - 1];
}

// time: O(n), space:O(1)
int minCostClimbingStairs(vector<int> &cost)
{

    if (cost.size() == 0)
    {
        return 0;
    }
    else if (cost.size() == 1)
    {
        return cost[0];
    }
    int prevPrevIndex = 0, prevIndex = 1, prevPrevVal = cost[0], prevVal = cost[1], tempIndex, tempVal;

    for (int i = 2; i < cost.size(); i++)
    {
        tempVal = min(prevPrevVal + cost[i], prevVal + cost[i]);
        prevPrevIndex = prevIndex;
        prevIndex = i;
        prevPrevVal = prevVal;
        prevVal = tempVal;
    }
    tempVal = min(prevPrevVal + 0, prevVal + 0);
    return tempVal;
}

int main()
{
}