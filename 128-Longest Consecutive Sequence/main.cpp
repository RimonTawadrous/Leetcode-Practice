#include <bits/stdc++.h>
using namespace std;

int fillHashmap(unordered_map<int, int> &numberPresense, int number)
{

    if (numberPresense.find(number) == numberPresense.end())
    {
        return 0;
    }
    numberPresense[number] = fillHashmap(numberPresense, number - 1)+1;
    return numberPresense[number];
}

int longestConsecutive(vector<int> &nums)
{
    unordered_map<int, int> numberPresense;
    int max = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        numberPresense[nums[i]] = -1;
    }

    for (int i = 0; i < nums.size(); i++)
    {
        if (numberPresense[nums[i]] == -1)
        {
            fillHashmap(numberPresense, nums[i]);
        }
    }
    for (auto &it : numberPresense)
    {
        if(max < it.second){
            max = it.second;
        }
    }
    return max;
}

int main()
{
    // vector<int> nums = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
        vector<int> nums = {100,4,200,1,3,2};

    longestConsecutive(nums);
}