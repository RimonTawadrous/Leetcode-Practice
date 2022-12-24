#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int rows = 0, cols = 0;

public:
    bool isToeplitzMatrix(vector<vector<int>> &matrix)
    {
        rows = matrix.size();
        cols = matrix[0].size();
        for (int i = 0; i < cols; i++)
        {
            int row = 0, col = i;
            int number = matrix[row][col];
            for (int j = 0; j < rows; j++)
            {
                if (isInbound(row + j, col + j))
                {
                    if (number != matrix[row + j][col + j])
                    {
                        return false;
                    }
                }
            }
        }

        for (int i = rows - 1; i > 0; i--)
        {
            int row = i, col = 0;
            int number = matrix[row][col];
            for (int j = 0; j < cols; j++)
            {
                if (isInbound(row + j, col + j))
                {
                    if (number != matrix[row + j][col + j])
                    {
                        return false;
                    }
                }
            }
        }

        return true;
    }

    bool isInbound(int row, int col)
    {
        return row < rows && col < cols;
    }
};

int main()
{
}