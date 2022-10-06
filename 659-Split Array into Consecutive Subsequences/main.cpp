#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPossible(vector<int> &nums)
    {
        unordered_map<int, int> ones;
        unordered_map<int, int> twos;
        unordered_map<int, int> threeAndMore;

        for (int num : nums)
        {
            if (ones.find(num - 1) != ones.end())
            {
                ones[num - 1]--;
                twos[num] += 1;
                if (ones[num - 1] == 0)
                {
                    ones.erase(num - 1);
                }
            }
            else if (twos.find(num - 1) != twos.end())
            {

                twos[num - 1]--;
                threeAndMore[num] += 1;
                if (twos[num - 1] == 0)
                {
                    twos.erase(num - 1);
                }
            }
            else if (threeAndMore.find(num - 1) != threeAndMore.end())
            {
                threeAndMore[num - 1]--;
                threeAndMore[num] += 1;
                if (threeAndMore[num - 1] == 0)
                {
                    threeAndMore.erase(num - 1);
                }
            }
            else
            {
                ones[num] += 1;
            }
        }

        if (!ones.empty() || !twos.empty())
        {
            return false;
        }
        return true;
    }
};

int main()
{
    vector<int> test = {1, 2, 3, 4, 4, 5};
    Solution s;
    s.isPossible(test);
}