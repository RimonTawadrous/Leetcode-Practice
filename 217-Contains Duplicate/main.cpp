#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_map<int, int> freqs;
        for (int num : nums)
        {
            freqs[num]++;
            if (freqs[num] > 1)
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{
}