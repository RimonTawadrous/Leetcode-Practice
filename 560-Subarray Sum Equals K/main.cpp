#include <bits/stdc++.h>
using namespace std;

int subarraySum(vector<int> &nums, int k)
{
    map<int, int> sums;
    int currentSum = 0, totalKs = 0;
    sums[0] = 1;
    for (size_t i = 0; i < nums.size(); i++)
    {
        currentSum += nums[i];

        if (sums.find(currentSum - k) != sums.end())
        {
            totalKs += sums[currentSum - k];
        }

        sums[currentSum] += 1;
    }
    return totalKs;
}

int main()
{
    vector<int> test = {1, 1, 1};
    cout << subarraySum(test, 2) << endl;
}