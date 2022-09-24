#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int side_length;

public:
    bool backTrack(vector<int> &matchsticks, vector<int> &sides, int index)
    {
        if (index == matchsticks.size())
        {
            return true;
        }
        for (int i = 0; i < 4; ++i)
        {
            if ((sides[i] + matchsticks[index]) <= side_length)
            {
                sides[i] += matchsticks[index];
                if (backTrack(matchsticks, sides, index + 1))
                {
                    // cout << "yes = " << side_length << endl;
                    return true;
                }
                sides[i] -= matchsticks[index];
            }
        }
        return false;
    }

    bool makesquare(vector<int> &matchsticks)
    {
        int premiter = accumulate(matchsticks.begin(), matchsticks.end(), 0);

        if (premiter % 4 != 0)
        {
            return false;
        }
        vector<int> sides(4, 0);
        this->side_length = premiter / 4;
        sort(matchsticks.rbegin(), matchsticks.rend());
        // cout << "endl" << endl;
        return backTrack(matchsticks, sides, 0);
    }
};

int main()
{
    Solution s;
    vector<int> test = {1, 1, 2, 2, 2};
    cout << s.makesquare(test);
}