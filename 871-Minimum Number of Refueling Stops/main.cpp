#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    struct myComp
    {
        const bool operator()(
            pair<int, int> const &a,
            pair<int, int> const &b)
        {
            return a.second < b.second;
        }
    };

public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>> &stations)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, myComp> stationsPQ;
        int maxRange = startFuel, refillCount = 0, i = 0;

        while (maxRange < target)
        {
            while (i < stations.size() && maxRange >= stations[i][0])
            {
                stationsPQ.push(make_pair(stations[i][0], stations[i][1]));
                i++;
            }

            if (stationsPQ.empty())
            {
                return -1;
            }
            maxRange += stationsPQ.top().second;
            stationsPQ.pop();
            refillCount++;
        }
        return refillCount;
    }
};

int main()
{
}
