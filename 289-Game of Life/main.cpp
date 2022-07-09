#include <bits/stdc++.h>
using namespace std;

bool isvalidCord(int rowInd, int colInd, int rowsNum, int colsNum)
{
    return (rowInd > -1 && rowInd < rowsNum && colInd > -1 && colInd < colsNum);
}

void gameOfLife(vector<vector<int>> &board)
{
    vector<int> dx = {-1, -1, -1, 0, 0, 1, 1, 1};
    vector<int> dy = {-1, 0, 1, -1, 1, -1, 0, 1};
    int rowsNum = board.size();
    int colsNum = board[0].size();

    int neighbourX = 0, neighbourY = 0;

    for (size_t rowInd = 0; rowInd < board.size(); rowInd++)
    {
        for (size_t colInd = 0; colInd < board[rowInd].size(); colInd++)
        {
            int alive_neigbour_sum = 0;

            for (size_t k = 0; k < dx.size(); k++)
            {
                neighbourX = rowInd + dx[k];
                neighbourY = colInd + dy[k];
                if (isvalidCord(neighbourX, neighbourY, rowsNum, colsNum) && abs(board[neighbourX][neighbourY]) == 1)
                {
                    alive_neigbour_sum++;
                }
            }

            if (board[rowInd][colInd] == 1 && (alive_neigbour_sum < 2 || alive_neigbour_sum > 3))
            {
                board[rowInd][colInd] = -1;
            }
            else if (board[rowInd][colInd] == 0 && alive_neigbour_sum == 3)
            {
                board[rowInd][colInd] = 2;
            }
        }
    }

    for (size_t rowInd = 0; rowInd < board.size(); rowInd++)
    {
        for (size_t colInd = 0; colInd < board[rowInd].size(); colInd++)
        {
            if (board[rowInd][colInd] >= 1)
            {
                board[rowInd][colInd] = 1;
            }
            else
            {
                board[rowInd][colInd] = 0;
            }
        }
    }
}

int main()
{
}