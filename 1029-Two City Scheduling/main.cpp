#include <bits/stdc++.h>
using namespace std;
bool comparetor(vector<int> first, vector<int> second)
{
    int firstDiff = first[0] - first[1];
    int secondDiff = second[0] - second[1];

    if (firstDiff < secondDiff)
    {
        return true;
    }
    return false;
}

int twoCitySchedCost(vector<vector<int>> &costs)
{
    sort(costs.begin(), costs.end(), comparetor);
    int cost = 0;
    for (size_t i = 0; i < costs.size() / 2; i++)
    {
        cost += costs[i][0];
        cout << "( " << costs[i][0] << " , " << costs[i][1] << " )" << endl;
    }
    for (size_t i = (costs.size() / 2); i < costs.size(); i++)
    {
        cost += costs[i][1];
        cout << "2( " << costs[i][0] << " , " << costs[i][1] << " )" << endl;
    }
    return cost;
}

int main()
{
    vector<int> first = {1, 2};
    vector<int> second = {1, 3};
    vector<vector<int>> costs = {{259, 770}, {448, 54}, {926, 667}, {184, 139}, {840, 118}, {577, 469}};
    cout << twoCitySchedCost(costs) << endl;
}