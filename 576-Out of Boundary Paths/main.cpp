class Solution
{
public:
    vector<vector<vector<int>>> dp;
    int MOD = 1e9 + 7;

    int dfs(int m, int n, int N, int i, int j)
    {
        if (i < 0 || i == m || j < 0 || j == n)
            return 1;
        if (N == 0)
            return 0;
        if (dp[N][i][j] >= 0)
            return dp[N][i][j];

        // dfs, not findPaths!!
        int a = dfs(m, n, N - 1, i, j - 1);
        int b = dfs(m, n, N - 1, i, j + 1);
        int c = dfs(m, n, N - 1, i - 1, j);
        int d = dfs(m, n, N - 1, i + 1, j);

        return dp[N][i][j] = (((a + b) % MOD + c) % MOD + d) % MOD;
    }

    int findPaths(int m, int n, int N, int i, int j)
    {
        if (i < 0 || i == m || j < 0 || j == n)
            return 1;
        if (N == 0)
            return 0;

        dp = vector<vector<vector<int>>>(N + 1, vector<vector<int>>(m, vector<int>(n, -1)));

        return dfs(m, n, N, i, j);
    }
};