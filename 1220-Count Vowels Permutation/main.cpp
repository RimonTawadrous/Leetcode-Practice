#include <bits/stdc++.h>
using namespace std;
int countVowelPermutation(int n)
{
    if (n == 0)
    {
        return 0;
    }

    enum chars
    {
        a = 0,
        e,
        i,
        o,
        u
    };
    vector<long> dp = {1, 1, 1, 1, 1};
    vector<long> temp = {1, 1, 1, 1, 1};
    int mod = 1e9 + 7, res = 0;
    for (int j = 1; j < n; j++)
    {
        memcpy(temp.data(), dp.data(), dp.size() * sizeof(long));
        dp[a] = (temp[e] + temp[i] + temp[u]) % mod;
        dp[e] = (temp[a] + temp[i]) % mod;
        dp[i] = (temp[e] + temp[o]) % mod;
        dp[o] = temp[i];
        dp[u] = (temp[i] + temp[o]) % mod;
    }
    for (int j = 0; j < 5; ++j)
    {
        res = (res + dp[j]) % mod;
    }
    return res;
}
int main()
{
    cout << countVowelPermutation(158) << endl;
}