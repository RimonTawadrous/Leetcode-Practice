#include <bits/stdc++.h>
using namespace std;
#include <stdio.h>

// int deleteAndEarn(vector<int> &nums)
// {
//     if (!nums.size())
//     {
//         return 0;
//     }

//     unordered_map<int, int> numberFreq;
//     int maxNum = INT32_MIN;
//     for (int i = 0; i < nums.size(); i++)
//     {
//         numberFreq[nums[i]] += 1;
//         maxNum = max(maxNum, nums[i]);
//     }

//     vector<int> temp(maxNum + 1, 0);
//     temp[1] = numberFreq[1];

//     for (int i = 2; i < maxNum + 1; i++)
//     {
//         if (numberFreq[i])
//         {
//             temp[i] = max(numberFreq[i] * i + temp[i - 2], temp[i - 1]);
//         }
//         else
//         {
//             temp[i] = temp[i - 1];
//         }
//     }
//     return temp[temp.size() - 1];
// }

// int deleteAndEarn(vector<int> &nums)
// {
//     if (!nums.size())
//     {
//         return 0;
//     }

//     unordered_map<int, int> numberFreq;
//     int maxNum = INT32_MIN;
//     for (int i = 0; i < nums.size(); i++)
//     {
//         numberFreq[nums[i]] += 1;
//         maxNum = max(maxNum, nums[i]);
//     }

//     vector<int> temp(maxNum + 1, 0);
//     temp[1] = numberFreq[1];

//     for (int i = 2; i < maxNum + 1; i++)
//     {
//         if (numberFreq[i])
//         {
//             temp[i] = max(numberFreq[i] * i + temp[i - 2], temp[i - 1]);
//         }
//         else
//         {
//             temp[i] = temp[i - 1];
//         }
//     }
//     return temp[temp.size() - 1];
// }

int microsoft(vector<int> &vec)
{
    long long int totalblance = 0;
    int numberOfMoves = 0;
    int minNegative = INT32_MAX;
    for (int i = 0; i < vec.size(); i++)
    {
        totalblance += vec[i];
        if (vec[i] < 0)
        {
            minNegative = min(minNegative, vec[i]);
        }
        if (totalblance < 0)
        {
            numberOfMoves++;
            totalblance += (-1 * minNegative);
        }
    }
    return numberOfMoves;
}

int main()
{
    // vector<int> v = {2, 2, 3, 3, 3, 4};
    vector<int> v = {10, -10, -1, -1, 1};

    // cout << deleteAndEarn(v) << endl;
    cout << microsoft(v) << endl;

    return 0;
}