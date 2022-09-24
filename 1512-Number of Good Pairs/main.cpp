#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numIdenticalPairs(vector<int> &nums)
    {
        vector<int> freq(101, 0);
        int count = 0;
        for (int num : nums)
        {
            count += freq[num]++;
        }
        return count;
    }
};