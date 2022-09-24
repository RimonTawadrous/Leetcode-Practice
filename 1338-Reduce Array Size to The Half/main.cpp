#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minSetSize(vector<int> &arr)
    {
        unordered_map<int, int> freqs;
        priority_queue<pair<int, int>> pq;

        for (int number : arr)
        {
            if (freqs.find(number) == freqs.end())
            {
                freqs[number] = 0;
            }
            freqs[number]++;
        }

        for (auto it : freqs)
        {
            pq.push(make_pair(it.second, it.first));
        }

        int remainingSize = arr.size();
        int res = 0;
        while (remainingSize > arr.size() / 2 && !pq.empty())
        {
            remainingSize -= pq.top().first;
            pq.pop();
            res++;
        }
        return res;
    }
};

int main()
{
    vector<int> test = {3, 3, 3, 3, 5, 5, 5, 2, 2, 7};
    Solution s;
    s.minSetSize(test);
    return 0;
}