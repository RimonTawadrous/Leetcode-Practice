#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    vector<vector<bool>> visited;
    int rows, cols;

public:
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        rows = grid.size();
        if (rows == 0)
        {
            return 0;
        }
        cols = grid[0].size();
        visited = vector<vector<bool>>(rows, vector<bool>(cols, false));
        int maxArea = 0;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (grid[i][j] == 1 && !visited[i][j])
                {
                    maxArea = max(maxArea, areaDFS(grid, i, j));
                }
            }
        }
        return maxArea;
    }

    int areaDFS(vector<vector<int>> &grid, int row, int col)
    {
        if (row < 0 || col < 0 || row == rows || col == cols || visited[row][col] || grid[row][col] == 0)
        {
            return 0;
        }
        visited[row][col] = true;

        return (1 + areaDFS(grid, row - 1, col) + areaDFS(grid, row + 1, col) + areaDFS(grid, row, col + 1));
    }
};

int main()
{
    Solution s;
    vector<vector<int>> grid = {{0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                                {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                                {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
                                {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
                                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                                {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                                {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}};
    cout << "ans = " << s.maxAreaOfIsland(grid);
}