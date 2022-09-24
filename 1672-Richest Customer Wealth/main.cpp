#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumWealth(vector<vector<int>> &accounts)
    {
        int maxWealth = 0, tempWealth = 0;
        for (vector<int> account : accounts)
        {
            tempWealth = accumulate(account.begin(), account.end(), 0);
            if (tempWealth > maxWealth)
            {
                maxWealth = tempWealth;
            }
        }
        return maxWealth;
    }
};