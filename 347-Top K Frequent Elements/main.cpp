#include <bits/stdc++.h>
using namespace std;

vector<int> topKFrequent(vector<int> &nums, int k)
{
    unordered_map<int, int> freqs;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> PrQ;
    for (int number : nums)
    {
        freqs[number]++;
    }

    for (auto it = freqs.begin(); it != freqs.end(); it++)
    {
        if (PrQ.size() < k)
        {
            PrQ.push(make_pair(it->second, it->first));
        }
        else if ((PrQ.top().first) < (it->second))
        {
            PrQ.pop();
            PrQ.push(make_pair(it->second, it->first));
        }
    }

    vector<int> res;

    while (k > 0)
    {
        pair<int, int> temp = PrQ.top();
        PrQ.pop();
        res.push_back(temp.second);
        k--;
    }

    return res;
}

int main()
{
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;
    vector<int> res = topKFrequent(nums, k);

    for (auto val : res)
    {
        cout << val << endl;
    }
}
