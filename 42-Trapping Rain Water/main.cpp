#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int trap(vector<int> &height)
    {
        if (!height.size())
        {
            return 0;
        }
        int area = 0, maxLeft = height[0], maxRight = height[height.size() - 1];
        int left = 0, right = height.size() - 1;
        while (left < right)
        {
            if (maxLeft <= maxRight)
            {
                left++;
                maxLeft = max(maxLeft, height[left]);
                area += maxLeft - height[left];
            }
            else
            {
                right--;
                maxRight = max(maxRight, height[right]);
                area += maxRight - height[right];
            }
        }
        return area;
    }
};

int main()
{
}