#include <bits/stdc++.h>
using namespace std;

// class TimeMap
// {
// private:
//     int count = 0;
//     unordered_map<string, map<int, string>> store;

// public:
//     TimeMap()
//     {
//     }

//     void set(string key, string value, int timestamp)
//     {
//         store[key].insert({timestamp, value});
//     }

//     string get(string key, int timestamp)
//     {
//         auto it = store[key].upper_bound(timestamp);
//         return it == store[key].begin() ? "" : prev(it)->second;
//     }
// };

class TimeMap
{
private:
    int count = 0;
    unordered_map<string, vector<pair<string, int>>> store;

public:
    TimeMap()
    {
    }

    void set(string key, string value, int timestamp)
    {
        if (store.find(key) == store.end())
        {
            store[key] = {make_pair(value, timestamp)};
        }
        else
        {
            store[key].push_back(make_pair(value, timestamp));
        }
    }

    string get(string key, int timestamp)
    {
        string res = "";
        if (store.find(key) != store.end())
        {
            vector<pair<string, int>> tempVect = store[key];
            int lo = 0, hi = tempVect.size() - 1, mid = lo + (hi - lo) / 2;
            while (lo < hi)
            {
                mid = lo + (hi - lo) / 2;
                if (tempVect[mid].second <= timestamp)
                {
                    res = tempVect[mid].first;
                    lo = mid + 1;
                }
                else
                {
                    hi = mid;
                }
            }
        }
        return res;
    }
};

int main()
{
}