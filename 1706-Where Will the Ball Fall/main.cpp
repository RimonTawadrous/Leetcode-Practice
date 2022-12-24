#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int rowsNum = 0, colsNum = 0;
    vector<int> ans;

public:
    vector<int> findBall(vector<vector<int>> &grid)
    {
        rowsNum = grid.size();
        colsNum = grid[0].size();

        for (int i = 0; i < colsNum; i++)
        {
            dfs(0, i, grid);
        }
        return ans;
    }

    void dfs(int row, int col, vector<vector<int>> &grid)
    {
        if (row >= rowsNum)
        {
            ans.push_back(col);
        }

        else if (grid[row][col] == -1 && col == 0)
        {
            ans.push_back(-1);
        }

        else if (grid[row][col] == -1 && col > 0 && grid[row][col - 1] == 1)
        {
            ans.push_back(-1);
        }

        else if (grid[row][col] == 1 && col == colsNum - 1)
        {
            ans.push_back(-1);
        }

        else if (grid[row][col] == 1 && col < colsNum && grid[row][col + 1] == -1)
        {
            ans.push_back(-1);
        }
        else
        {
            if (grid[row][col] == 1)
            {
                dfs(row + 1, col + 1, grid);
            }
            else
            {
                dfs(row + 1, col - 1, grid);
            }
        }
    }

    bool isElementInbound(int row, int col)
    {
        return row < rowsNum && col < colsNum;
    }
};

int main()
{
}