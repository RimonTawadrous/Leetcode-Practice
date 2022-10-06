#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findOriginalArray(vector<int> &changed)
    {
        if (changed.size() % 2 != 0)
        {
            return {};
        }

        sort(changed.begin(), changed.end());
        unordered_map<int, int> numbersFreq;
        vector<int> res;

        for (int number : changed)
        {
            numbersFreq[number]++;
        }
        for (int number : changed)
        {
            if (number == 0 && numbersFreq[number] > 1)
            {
                res.push_back(number);
                numbersFreq[number] -= 2;
            }
            else if (number > 0 && numbersFreq[number] > 0 && numbersFreq[number * 2] > 0)
            {
                res.push_back(number);
                numbersFreq[number]--;
                numbersFreq[number * 2]--;
            }
        }

        if (res.size() != changed.size() / 2)
        {
            return {};
        }
        return res;
    }
};

int main()
{
}