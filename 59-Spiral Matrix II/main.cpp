#include <bits/stdc++.h>
using namespace std;

// vector<vector<int>> generateMatrix(int n)
// {
//     vector<vector<int>> res(n,  vector<int>(n,0));
//     int top = 0, bottom = n - 1;
//     int left = -1, right = n - 1;
//     int number = 1;
//     if(n ==1){
//         res[0][0] = 1;
//         return res;
//     }
//     while (top <= bottom)
//     {
//         left++;
//         for (size_t i = left; i <= right; i++)
//         {
//             res[top][i] = number++;
//         }
//         for (size_t i = top+1; i <= bottom; i++)
//         {
//             res[i][right] = number++;
//         }
//         for (size_t i = right-1; i > left; i--)
//         {
//             res[bottom][i] = number++;
//         }
//         top++;
//         right--;
//         for (size_t i = bottom; i >= top; i--)
//         {
//             res[i][left] = number++;
//         }
//         bottom--;
//     }
//     return res;
// }

vector<vector<int>> generateMatrix(int n)
{
    vector<vector<int>> res(n, vector<int>(n, 0));
    int top = 0, bottom = n - 1;
    int left = 0, right = n - 1;
    int number = 1;
    if (n == 1)
    {
        res[0][0] = 1;
        return res;
    }
    while (top <= bottom)
    {
        for (size_t i = left; i <= right; i++)
        {
            res[top][i] = number++;
        }
        for (size_t i = top + 1; i <= bottom; i++)
        {
            res[i][right] = number++;
        }
        for (size_t i = right - 1; i > left; i--)
        {
            res[bottom][i] = number++;
        }
        for (size_t i = bottom; i > top; i--)
        {
            res[i][left] = number++;
        }
        top++;
        left++;
        right--;
        bottom--;
    }
    return res;
}

int main()
{
    int n = 5;
    vector<vector<int>> res = generateMatrix(n);
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            cout << res[i][j] << "  ";
        }
        cout << "\n";
    }
    return 0;
}