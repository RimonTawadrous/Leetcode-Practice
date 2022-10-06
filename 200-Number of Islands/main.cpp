#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    vector<vector<bool>> visited;
    int rows, cols;

public:
    int numIslands(vector<vector<char>> &grid)
    {
        rows = grid.size();
        if (rows == 0)
        {
            return 0;
        }
        cols = grid[0].size();
        visited = vector<vector<bool>>(rows, vector<bool>(cols, false));
        int numberOfIslandes = 0;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (grid[i][j] == '1' && !visited[i][j])
                {
                    numberOfIslandes++;
                    discoverIsland(grid, i, j);
                }
            }
        }
        return numberOfIslandes;
    }
    void discoverIsland(vector<vector<char>> &grid, int row, int col)
    {
        if (row < 0 || col < 0 || row == rows || col == cols || grid[row][col] == '0' || visited[row][col])
        {
            return;
        }
        visited[row][col] = true;
        discoverIsland(grid, row - 1, col);
        discoverIsland(grid, row + 1, col);
        discoverIsland(grid, row, col - 1);
        discoverIsland(grid, row, col + 1);
    }
};

int main()
{
}
