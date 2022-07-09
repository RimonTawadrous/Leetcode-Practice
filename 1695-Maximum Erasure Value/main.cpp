#include <bits/stdc++.h>
using namespace std;

int maximumUniqueSubarray(vector<int> &nums)
{
    map<int, int> lastOccuranceMap;
    int firstIndex = 0, maxSum = 0, tempSum = 0;
    vector<int> sumVector(nums.size() + 1);

    sumVector[0] = 0;
    for (size_t i = 0; i < nums.size(); i++)
    {
        sumVector[i + 1] += sumVector[i] + nums[i];
    }

    // for (size_t i = 0; i < sumVector.size(); i++)
    // {
    //     cout << sumVector[i] << " ";
    // }
    // cout << "\n";

    for (size_t i = 0; i < nums.size(); i++)
    {
        if (lastOccuranceMap.find(nums[i]) != lastOccuranceMap.end())
        {
            firstIndex = max(firstIndex, (int)(lastOccuranceMap[nums[i]] + 1));
        }

        lastOccuranceMap[nums[i]] = i;
        tempSum = sumVector[i + 1] - sumVector[firstIndex];
        // cout << tempSum << " ";

        maxSum = max(maxSum, tempSum);
    }

    return maxSum;
}

int main()
{
    // vector<int> test = {5, 2, 1, 2, 5, 2, 1, 2, 5};
    vector<int> test = {10000};

    cout << maximumUniqueSubarray(test) << endl;
}