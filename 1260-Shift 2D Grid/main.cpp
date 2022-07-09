#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> shiftGrid(vector<vector<int>> &grid, int k)
{
    int size = grid.size() * grid[0].size();
    int actualShift = k % size;
    if (actualShift == 0)
    {
        return grid;
    }
    vector<vector<int>> res;
    int shiftRow =  grid.size() - max((int)ceil((actualShift / (double)grid[0].size())), 1);
    int shiftCol = (grid[0].size() - (actualShift % grid[0].size())) % grid[0].size();
    int newMatrixRowIndex = 0, newMatrixColIndex = 0;
    for (size_t i = 0; i < grid.size(); i++)
    {
        vector<int> temp(grid[0].size(), 0);
        res.push_back(temp);
    }

    while (newMatrixRowIndex < grid.size())
    {
        newMatrixColIndex = 0;
        while (newMatrixColIndex < grid[0].size())
        {

            if (shiftCol == (grid[0].size()))
            {
                shiftRow++;
                shiftCol = 0;
                if (shiftRow == grid.size())
                {
                    break;
                }
            }
            cout << "( " << shiftRow << " , " << shiftCol << " ===>> "
                 << "( " << newMatrixRowIndex << " , " << newMatrixColIndex << endl;
            res[newMatrixRowIndex][newMatrixColIndex] = grid[shiftRow][shiftCol];
            newMatrixColIndex++;
            shiftCol++;
        }
        if (shiftRow == grid.size())
        {
            break;
        }
        newMatrixRowIndex++;
    }

    for (size_t i = 0; i < res.size(); i++)
    {
        for (size_t j = 0; j < res[0].size(); j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    cout << newMatrixColIndex << endl;
    cout << newMatrixRowIndex << endl;

    shiftRow = grid.size() - max((int)ceil((actualShift / (double)grid[0].size())), 1);
    shiftCol = (grid[0].size() - (actualShift % grid[0].size())) % grid[0].size();
    int i = 0, j = 0;
    while (newMatrixRowIndex < grid.size())
    {
        while (newMatrixColIndex < grid[0].size())
        {
            if (j == (grid[0].size()))
            {
                i++;
                j = 0;
                if (i == shiftRow && j == shiftCol)
                {
                    return res;
                }
            }
            res[newMatrixRowIndex][newMatrixColIndex] = grid[i][j];
            newMatrixColIndex++;
            j++;
        }
        newMatrixColIndex = 0;
        newMatrixRowIndex++;
    }
    return res;
}

int main()
{
    // vector<vector<int>> test = {{3, 8, 1, 9}, {19, 7, 2, 5}, {4, 6, 11, 10}, {12, 0, 21, 13}};
    // int k = 4;

    vector<vector<int>> test = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int k = 1;
    vector<vector<int>> res = shiftGrid(test, k);

    for (size_t i = 0; i < res.size(); i++)
    {
        for (size_t j = 0; j < res[0].size(); j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}