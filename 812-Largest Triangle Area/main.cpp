#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double largestTriangleArea(vector<vector<int>> &points)
    {
        int LargestX = 0;
        int LargestY = 0;

        for (vector<int> point : points)
        {
            if (abs(point[0]) > LargestX)
            {
                LargestX = point[0];
            }
            else if (abs(point[1]) > LargestY)
            {
                LargestY = point[1];
            }
        }

        double res = (abs(LargestX) * abs(LargestY)) / 2;
        return res;
    }
};

int main()
{
}