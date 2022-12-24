#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        unordered_map<int, int> valueToIndexMap;
        for (int i = 0; i < nums.size(); i++)
        {
            if (valueToIndexMap.find(nums[i]) != valueToIndexMap.end() && abs(valueToIndexMap[nums[i]] - i) <= k)
            {
                return true;
            }
            valueToIndexMap[nums[i]] = i;
        }
        return false;
    }
};

int main()
{
}