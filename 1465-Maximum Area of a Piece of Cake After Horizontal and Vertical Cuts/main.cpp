#include <bits/stdc++.h>
using namespace std;
int maxArea(int h, int w, vector<int> &horizontalCuts, vector<int> &verticalCuts)
{
    long long maxVerticalDiff = 0, maxHorizontalDiff = 0;
    sort(horizontalCuts.begin(), horizontalCuts.end());
    sort(verticalCuts.begin(), verticalCuts.end());
    vector<int> horizontalCutsDiff;
    vector<int> verticalCutsDiff;
    horizontalCutsDiff.reserve(horizontalCuts.size() + 1);
    verticalCutsDiff.reserve(verticalCuts.size() + 1);
    horizontalCutsDiff.push_back(horizontalCuts[0]);
    verticalCutsDiff.push_back(verticalCuts[0]);
    horizontalCutsDiff.push_back(h - horizontalCuts[horizontalCuts.size() - 1]);
    verticalCutsDiff.push_back(w - verticalCuts[verticalCuts.size() - 1]);

    for (size_t i = 1; i < horizontalCuts.size(); i++)
    {
        horizontalCutsDiff.push_back(horizontalCuts[i] - horizontalCuts[i - 1]);
    }
    for (size_t i = 1; i < verticalCuts.size(); i++)
    {
        verticalCutsDiff.push_back(verticalCuts[i] - verticalCuts[i - 1]);
    }
    for (size_t i = 0; i < horizontalCutsDiff.size(); i++)
    {
        if (maxHorizontalDiff < horizontalCutsDiff[i])
        {
            maxHorizontalDiff = horizontalCutsDiff[i];
        }
    }
    for (size_t i = 0; i < verticalCutsDiff.size(); i++)
    {
        if (maxVerticalDiff < verticalCutsDiff[i])
        {
            maxVerticalDiff = verticalCutsDiff[i];
        }
    }
    return (maxHorizontalDiff * maxVerticalDiff) % 1000000007;
}
int main()
{
}