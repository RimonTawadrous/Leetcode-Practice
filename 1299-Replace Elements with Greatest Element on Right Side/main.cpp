#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> replaceElements(vector<int> &arr)
    {
        vector<int> ans(arr.size());
        int max = -1;

        for (int i = arr.size()-1; i > -1; i--)
        {
            ans[i] = max;
            if (arr[i] > max)
            {
                max = arr[i];
            }
        }
        return ans;
    }
};

int main()
{
}