#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    struct hashFunction
    {
        size_t operator()(const pair<int,
                                     int> &x) const
        {
            return x.first ^ x.second;
        }
    };
    unordered_set<pair<int, int>, hashFunction> visited;

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {

        if (heights.empty())
        {
            return {};
        }
        bool isReachPacific = false;
        bool isReachAtlantic = false;
        vector<vector<int>> results;
        for (int i = 0; i < heights.size(); i++)
        {
            for (int j = 0; j < heights[0].size(); j++)
            {

                visited.clear();

                isReachPacific = reachPacific(heights, i, j);
                visited.clear();
                // cout << ">>" << i << " " << j << endl;
                isReachAtlantic = reachAtlantic(heights, i, j);
                // cout << "=================================" << endl;

                if (isReachPacific && isReachAtlantic)
                {
                    cout << i << " " << j << endl;
                    results.push_back({i, j});
                }
            }
        }
        return results;
    }

    bool reachPacific(vector<vector<int>> &heights, int cellR, int cellC)
    {
        if (cellR == 0 || cellC == 0)
        {
            return true;
        }

        bool hasAccess = false;
        visited.insert(make_pair(cellR, cellC));

        if ((heights[cellR][cellC] >= heights[cellR - 1][cellC]) && (visited.find(make_pair(cellR - 1, cellC)) == visited.end()))
        {
            hasAccess = reachPacific(heights, cellR - 1, cellC);
        }
        if (!hasAccess && (heights[cellR][cellC] >= heights[cellR][cellC - 1]) && (visited.find(make_pair(cellR, cellC - 1)) == visited.end()))
        {
            hasAccess = reachPacific(heights, cellR, cellC - 1);
        }
        if (!hasAccess && cellR + 1 < heights.size() && (heights[cellR][cellC] >= heights[cellR + 1][cellC]) && (visited.find(make_pair(cellR + 1, cellC)) == visited.end()))
        {
            hasAccess = reachPacific(heights, cellR + 1, cellC);
        }
        if (!hasAccess && cellC + 1 < heights[0].size() && (heights[cellR][cellC] >= heights[cellR][cellC + 1]) && (visited.find(make_pair(cellR, cellC + 1)) == visited.end()))
        {
            hasAccess = reachPacific(heights, cellR, cellC + 1);
        }
        return hasAccess;
    }

    bool reachAtlantic(vector<vector<int>> &heights, int cellR, int cellC)
    {
        if (cellR == heights.size() - 1 || cellC == heights[0].size() - 1)
        {
            return true;
        }

        bool hasAccess = false;
        visited.insert(make_pair(cellR, cellC));
        // cout << cellR << " " << cellR << "  " << heights[cellR + 1][cellC] << endl;

        if (cellR - 1 >= 0 && (heights[cellR][cellC] >= heights[cellR - 1][cellC]) && (visited.find(make_pair(cellR - 1, cellC)) == visited.end()))
        {
            hasAccess = reachAtlantic(heights, cellR - 1, cellC);
        }
        if (!hasAccess && cellC - 1 >= 0 && (heights[cellR][cellC] >= heights[cellR][cellC - 1]) && (visited.find(make_pair(cellR, cellC - 1)) == visited.end()))
        {
            hasAccess = reachAtlantic(heights, cellR, cellC - 1);
        }
        if (!hasAccess && (heights[cellR][cellC] >= heights[cellR + 1][cellC]) && (visited.find(make_pair(cellR + 1, cellC)) == visited.end()))
        {
            hasAccess = reachAtlantic(heights, cellR + 1, cellC);
        }
        if (!hasAccess && (heights[cellR][cellC] >= heights[cellR][cellC + 1]) && (visited.find(make_pair(cellR, cellC + 1)) == visited.end()))
        {
            hasAccess = reachAtlantic(heights, cellR, cellC + 1);
        }
        return hasAccess;
    }
};

int main()
{
    Solution s;
    // vector<vector<int>> heights = {{1, 2, 2, 3, 5}, {3, 2, 3, 4, 4}, {2, 4, 5, 3, 1}, {6, 7, 1, 4, 5}, {5, 1, 1, 2, 4}};
    vector<vector<int>> heights = {{1, 2, 3, 4}, {12, 13, 14, 5}, {11, 16, 15, 6}, {10, 9, 8, 7}};

    s.pacificAtlantic(heights);
}
