#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> diagonalSort(vector<vector<int>> &mat)
    {
        int rows = mat.size() - 1;
        int cols = mat[0].size() - 1;
        for (int col = 0; col < mat[0].size(); col++)
        {
            vector<int> temp;
            for (int k = 0; k < mat.size(); k++)
            {
                if (k + col > cols)
                {
                    break;
                }
                temp.push_back(mat[k][k + col]);
            }
            sort(temp.begin(), temp.end());
            for (int k = 0; k < temp.size(); k++)
            {
                mat[k][k + col] = temp[k];
            }
        }

        for (int row = 1; row < mat.size(); row++)
        {
            vector<int> temp;
            for (int k = 0; k < mat[0].size(); k++)
            {
                if (k + row > rows)
                {
                    break;
                }
                temp.push_back(mat[k + row][k]);
            }
            sort(temp.begin(), temp.end());
            for (int k = 0; k < temp.size(); k++)
            {
                mat[k + row][k] = temp[k];
            }
        }
        return mat;
    }
};

int main()
{
    // vector<vector<int>> mat = {{3, 3, 1, 1}, {2, 2, 1, 2}, {1, 1, 1, 2}};
    vector<vector<int>> mat = {{11, 25, 66, 1, 69, 7}, {23, 55, 17, 45, 15, 52}, {75, 31, 36, 44, 58, 8}, {22, 27, 33, 25, 68, 4}, {84, 28, 14, 11, 5, 50}};

    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = 0; j < mat[0].size(); j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << endl;
    cout << endl;

    Solution s;
    s.diagonalSort(mat);
}