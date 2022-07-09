#include <bits/stdc++.h>
using namespace std;
static bool compare(const vector<int> &v1, const vector<int> v2)
{
    return v1[1] > v2[1];
}

int maximumUnits(vector<vector<int>> &boxTypes, int truckSize)
{
    sort(boxTypes.begin(), boxTypes.end(), compare);
    int maxUnits = 0;
    for (vector<int> current : boxTypes)
    {
        if (truckSize > current[0])
        {
            maxUnits += current[0] * current[1];
            truckSize -= current[0];
        }
        else if (truckSize > 0)
        {
            maxUnits += truckSize * current[1];
            truckSize = 0;
        }
        else
        {
            return maxUnits;
        }
    }
    return maxUnits;
}
int main()
{
    vector<vector<int>> test = {{5, 10}, {2, 5}, {4, 7}, {3, 9}};
    cout << maximumUnits(test, 10);
}