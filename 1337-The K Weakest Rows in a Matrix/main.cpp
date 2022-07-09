#include <bits/stdc++.h>
using namespace std;

// vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
// {
//     vector<pair<int, int>> rows_values;
//     rows_values.reserve(mat.size());
//     vector<int> results;
//     int rowValue = 0;
//     for (size_t i = 0; i < mat.size(); i++)
//     {
//         rowValue = 0;
//         for (size_t j = 0; j < mat[i].size(); j++)
//         {
//             rowValue += mat[i][j];
//         }
//         rows_values.push_back(make_pair(rowValue, i));
//     }

//     stable_sort(rows_values.begin(), rows_values.end());
//     size_t i = 0;
//     while (k > 0 && i < rows_values.size())
//     {
//         results.push_back(rows_values[i].second);
//         i++;
//         k--;
//     }
//     return results;
// }

vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
{
    vector<int> rows_values(mat.size());
    vector<int> results(k);
    int hi, lo, mid;
    int rowValue = 0;
    for (size_t i = 0; i < mat.size(); i++)
    {
        rowValue = 0;
        hi = mat[i].size() - 1;
        lo = 0;
        mid = hi / 2;
        while (lo <= hi)
        {
            if(mid == 1){
                lo = mid +1;
            }else{
                hi = mid - 1;
            }
                        cout<< "lo = " << lo<< endl;

            cout<< "mid = " << mid<< endl;
                        cout<< "hi = " << hi<< endl;

            mid = lo + (hi-lo)/2;
        }
        cout<< "yes = " << mid<< endl;
        rows_values[i] = hi * 1000 + i;
    }
    stable_sort(rows_values.begin(), rows_values.end());
    for (size_t i = 0; i < k; i++)
    {
        results[i] = rows_values[i] % 1000;
    }
    return results;
}

int main()
{
    vector<vector<int>> mat = {{1, 1, 0, 0, 0},
                               {1, 1, 1, 1, 0},
                               {1, 0, 0, 0, 0},
                               {1, 1, 0, 0, 0},
                               {1, 1, 1, 1, 1}};

    kWeakestRows(mat, 3);
}
