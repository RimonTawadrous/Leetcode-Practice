#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> sumEvenAfterQueries(vector<int> &nums, vector<vector<int>> &queries)
    {
        vector<int> res;
        int evenSum = 0;
        for (int j = 0; j < nums.size(); j++)
        {
            if (nums[j] % 2 == 0)
            {
                evenSum += nums[j];
            }
        }

        for (int i = 0; i < queries.size(); i++)
        {
            if (nums[queries[i][1]] % 2 == 0)
            {
                evenSum -= nums[queries[i][1]];
            }
            nums[queries[i][1]] = nums[queries[i][1]] + queries[i][0];
            if (nums[queries[i][1]] % 2 == 0)
            {
                evenSum += nums[queries[i][1]];
            }
            
            res.push_back(evenSum);
        }
        return res;
    }
};

int main()
{
}