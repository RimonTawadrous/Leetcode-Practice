#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    struct comparator
    {
        bool operator()(const pair<int, int> x1, const pair<int, int> x2)
        {
            return x1.second > x2.second;
        }
    };

public:
    int maxPerformance(int n, vector<int> &speed, vector<int> &efficiency, int k)
    {
        vector<pair<int, int>> engineers;
        for (int i = 0; i < speed.size(); i++)
        {
            engineers.push_back(make_pair(speed[i], efficiency[i]));
        }
        priority_queue<int, vector<int>, greater<int>> minHeap;
        sort(engineers.begin(), engineers.end(), comparator());
        long spd = 0, res = 0;
        for (int i = 0; i < speed.size(); i++)
        {
            if (minHeap.size() == k)
            {
                spd -= minHeap.top();
                minHeap.pop();
            }

            spd += engineers[i].first;
            minHeap.push(engineers[i].first);
            res = max(res, engineers[i].second * spd);
        }
        return res % 1000000007;
    }
};

int main()
{
    vector<int> speed = {2, 10, 3, 1, 5, 8};
    vector<int> efficiency = {5, 4, 3, 9, 7, 2};

    Solution s;
    cout << s.maxPerformance(6, speed, efficiency, 2);
}