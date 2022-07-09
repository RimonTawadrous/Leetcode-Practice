#include <bits/stdc++.h>
using namespace std;

static bool comparator(vector<int> &a, vector<int> &b)
{
    if (a[0] == b[0])
        return a[1] < b[1];

    return a[0] < b[0];
}

vector<vector<int>> reconstructQueue(vector<vector<int>> &people)
{

    int n = people.size();
    vector<vector<int>> ans(people.size(), vector<int>(2, -1));
    sort(people.begin(), people.end(), comparator);
    for (int i = 0; i < people.size(); ++i)
    {
        int count = people[i][1];
        for (int j = 0; j < n; ++j)
        {
            if (ans[j][0] == -1 && count == 0)
            {
                ans[j][0] = people[i][0];
                ans[j][1] = people[i][1];
                break;
            }
            else if (ans[j][0] == -1 || ans[j][0] >= people[i][0])
                count -= 1;
        }
    }
    return ans;
}

// easie but slower

// static bool sortcol(const vector<int> &v1, const vector<int> &v2)
// {
//     return v1[0] > v2[0] || (v1[0] == v2[0] && v1[1] < v2[1]);
// }

// vector<vector<int>> reconstructQueue(vector<vector<int>> &people)
// {
//     vector<vector<int>> returnValue;
//     sort(people.begin(), people.end(), sortcol);

//     for (vector<int> person : people)
//     {
//         returnValue.insert(returnValue.begin() + person[1], person);
//     }
//     return returnValue;
// }

int main()
{
    cout << "yes0";
    vector<vector<int>> test = {{7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2}};
    for (vector<int> person : test)
    {

        cout << "[ " << person[0] << " , " << person[1] << " ]"
             << "  ";
    }
    vector<vector<int>> rersult = reconstructQueue(test);
    for (vector<int> person : rersult)
    {

        cout << "[ " << person[0] << " , " << person[1] << " ]"
             << "  ";
    }
}