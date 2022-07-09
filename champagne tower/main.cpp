#include <bits/stdc++.h>
using namespace std;
#include <stdio.h>

// double champagneTower(int poured, int query_row, int query_glass)
// {
//     if (poured == 0)
//     {
//         return 0.0;
//     }
//     int totalNumberOfGlasses = (query_row * (query_row + 1)) / 2;
//     int prevpourNumber = query_row * 2;
//     double fillPercentage = (double)(poured - totalNumberOfGlasses) / pow(2,query_row);
//     fillPercentage = fillPercentage > 0 ? fillPercentage : 0.0;
//     cout << fillPercentage << endl;
//     if (query_glass == 1 || query_glass == query_row)
//     {
//         return fillPercentage;
//     }
//     fillPercentage = query_row * fillPercentage;
//     return fillPercentage > 1 ? 1 : fillPercentage;
// }

double champagneTower(int poured, int query_row, int query_glass)
{
    if (poured == 0)
    {
        return 0.0;
    }
    
    vector<vector<double>> v(102, vector<double>(102,0));
    v[0][0] = poured;
    for(int i=0; i<query_row; i++){
        for(int j=0; j<=i; j++){
            double flow = (v[i][j]-1)/2;

            if(flow > 0){
                v[i+1][j] += flow;
                v[i+1][j+1] += flow;
            }
        }
    }

    return min(1.0, v[query_row][query_glass]);
}

int main()
{
    cout << champagneTower(25, 6, 1) << endl;

    return 0;
}