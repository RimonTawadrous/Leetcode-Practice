#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int nextIndex = 0;
        int lastIndex = 0;
        int k = 0;
        while (lastIndex < nums.size())
        {
            if (nums[nextIndex] == nums[lastIndex])
            {
                lastIndex++;
            }
            else
            {
                nextIndex++;
                nums[nextIndex] = nums[lastIndex];
                lastIndex++;
                k++;
            }
        }
        return k;
    }
};

int main()
{
}