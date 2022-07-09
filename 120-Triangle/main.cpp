#include <bits/stdc++.h>
using namespace std;

int minimumTotal(vector<vector<int>> &triangle)
{
    vector<int> dpVector(triangle.size() + 1, 0);
    for (int i = (triangle.size() - 1); i > -1; i--)
    {
        for (size_t j = 0; j < triangle[i].size(); j++)
        {
            cout << triangle[i][j] << endl;
            dpVector[j] = triangle[i][j] + min(dpVector[j], dpVector[j + 1]);
        }
    }

    return dpVector[0];
}

int main()
{
}