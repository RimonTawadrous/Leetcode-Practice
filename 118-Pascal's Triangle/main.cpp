#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> ans(numRows);
    if (numRows > 0)
    {
        ans[0] = vector<int>(1, 1);
        for (int i = 1; i < numRows; i++)
        {
            ans[i] = vector<int>(i + 1, 1);
            for (int j = 1; j < i; j++)
            {
                ans[i][j] = ans[i - 1][j] + ans[i - 1][j - 1];
            }
        }
    }
    return ans;
}

int main()
{
    generate(5);
}