#include <bits/stdc++.h>
using namespace std;

int maxArea(vector<int> &height)
{
    int arraySize = height.size() - 1;
    int firstIT = 0, endIt = arraySize;
    int tempMaxArea = 0, maxArea = 0;
    maxArea = min(height[firstIT], height[endIt]) * (endIt - firstIT);

    while (firstIT < endIt)
    {

        tempMaxArea = min(height[firstIT], height[endIt]) * (endIt - firstIT);
        maxArea = max(maxArea, tempMaxArea);
        if (height[firstIT] >height[endIt])
        {
            endIt--;
        }
        else
        {
            firstIT++;
        }
    }
    return maxArea;
}

int main()
{

    vector<int> heights = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    // vector<int> heights = {1, 1};
    // vector<int> heights = {1, 2, 4, 3};
    // vector<int> heights = {2, 3, 4, 5, 18, 17, 6};
    cout << maxArea(heights) << endl;

    return 0;
}