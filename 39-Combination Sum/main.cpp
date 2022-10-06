#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void backtracking(vector<int> &candidates, vector<vector<int>> &ans, vector<int> &sub, int target, int index)
    {
        int total = accumulate(sub.begin(), sub.end(), 0);
        if (index == candidates.size() || total > target)
        {
            return;
        }
        else if (total == target)
        {
            ans.push_back(sub);
        }
        else
        {
            sub.push_back(candidates[index]);
            backtracking(candidates, ans, sub, target, index);

            sub.pop_back();
            backtracking(candidates, ans, sub, target, index + 1);
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> sub;
        backtracking(candidates, ans, sub, target, 0);
        return ans;
    }
};

int main()
{
}