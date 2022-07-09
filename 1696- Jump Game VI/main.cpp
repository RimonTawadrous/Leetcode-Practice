#include <bits/stdc++.h>
using namespace std;
// time limit
int maxResult(vector<int> &nums, int k)
{
    vector<int> dp(nums.size(), INT_MIN);
    dp[0] = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        for (int j = 1; i - j > -1 && j <= k; j++)
        {
            dp[i] = max(dp[i], (dp[i - j] + nums[i]));
        }
    }

    return dp[nums.size() - 1];
}

// nlogn and n space
int maxResult(vector<int> &nums, int k)
{
    pair<int, int> tempPair;
    int lastNumber = 0;
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(nums[0], 0));
    lastNumber = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        while (!pq.empty())
        {
            tempPair = pq.top();
            if (tempPair.second < i - k)
            {
                pq.pop();
            }
            else
            {
                lastNumber = nums[i] + tempPair.first;
                pq.push(make_pair(nums[i] + tempPair.first, i));
                break;
            }
        }
    }
    return lastNumber;
}

// n and n space
int maxResult(vector<int> &nums, int k)
{
    deque<int> dqueu;
    dqueu.push_front(0);

    for (int i = 1; i < nums.size(); i++)
    {
        nums[i] = nums[i] + nums[dqueu.front()];
        while (!dqueu.empty() && nums[i] >= nums[dqueu.back()])
        {
            dqueu.pop_back();
        }
        dqueu.push_back(i);
        if (i - dqueu.front() >= k)
        {
            dqueu.pop_front();
        }
    }
    return nums[nums.size() - 1];
}

int main()
{
}