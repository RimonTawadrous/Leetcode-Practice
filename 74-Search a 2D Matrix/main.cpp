#include <bits/stdc++.h>
using namespace std;

bool serachRow(vector<int> &row, int target)
{
    int lo = 0, hi = row.size() - 1, mid = hi / 2;
    while (lo <= hi)
    {
        if (row[mid] == target)
        {
            return true;
        }
        if (target < row[mid])
        {
            hi = mid - 1;
        }
        else
        {
            lo = mid + 1;
        }
        mid = lo + (hi - lo) / 2;
    }
    return false;
}

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int lo = 0, hi = matrix.size() - 1, mid = hi / 2;
    while (lo <= hi)
    {
        if (matrix[mid][0] <= target)
        {
            if (matrix[mid][0] == target)
            {
                return true;
            }
            else if (mid == matrix.size() - 1)
            {
                return serachRow(matrix[mid], target);
            }
            else if (matrix[mid + 1][0] > target)
            {
                return serachRow(matrix[mid], target);
            }
        }
        if (matrix[mid][0] > target)
        {
            hi = mid - 1;
        }
        else
        {
            lo = mid + 1;
        }
        mid = lo + (hi - lo) / 2;
    }
    return false;
}

int main()
{
    vector<vector<int>> matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    cout << searchMatrix(matrix, 10) << endl;
}