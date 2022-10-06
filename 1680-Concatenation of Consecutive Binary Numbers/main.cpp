#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int concatenatedBinary(int n)
    {
        uint64_t res = 0, len = 0;
        int MOD = (int)1000000007;
        for (int i = 1; i <= n; i++)
        {
            if ((i & (i - 1)) == 0)
            {
                len++;
            }
            res = ((res << len) % MOD + i) % MOD;
        }
        return res;
    }
};

int main()
{
    Solution s;
}