#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    unordered_map<int, int> umap;

    for (int i = 0; i < nums.size(); i++)
    {
        umap[nums[i]] = i;
    }

    int firstIndex = -1;
    int secondIndex = -1;
    for (int i = 0; i < nums.size(); i++)
    {
        if (umap[target - nums[i]] && umap[target - nums[i]] != i)
        {
            firstIndex = i;
            secondIndex = umap[target - nums[i]];
            break;
        }
    }
    return {firstIndex, secondIndex};
}

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> freq;
        vector<int> result(2, -1);
        for (int i = 0; i < nums.size(); i++)
        {
            freq[nums[i]] = i;
        }

        int fristIndex = -1, secondIndex = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (freq[target - nums[i]] && freq[target - nums[i]] != i)
            {
                result[0] = i;
                result[1] = freq[target - nums[i]];
                break;
            }
        }
        return result;
    }
};

int main()
{
}