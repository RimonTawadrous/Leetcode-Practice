#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool static comparePlayer(vector<int> i1, vector<int> i2)
    {
        return (i1[0] > i2[0]) || (i1[1] < i2[1]);
    }

public:
    int numberOfWeakCharacters(vector<vector<int>> &properties)
    {
        if (properties.empty())
        {
            return 0;
        }

        int count = 0;
        sort(properties.begin(), properties.end(),
             [](const auto &a, const auto &b)
             {
                 return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
             });
        int result = 0, max_d = 0;
        for (int i = properties.size() - 1; i >= 0; --i)
        {
            if (properties[i][1] < max_d)
            {
                ++result;
            }
            max_d = max(max_d, properties[i][1]);
        }
        return result;
    }
};

bool comparePlayer(vector<int> a, vector<int> b)
{
    return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
}

int main()
{
    // vector<vector<int>> test = {{2, 2}, {3, 3}};
    // vector<vector<int>> test = {{1, 5}, {10, 4}, {4, 3}};
    vector<vector<int>> test = {{7, 9}, {10, 7}, {6, 9}, {10, 4}, {7, 5}, {7, 10}};
    sort(test.begin(), test.end(), comparePlayer);
    for (vector<int> vect : test)
    {
        cout << vect[0] << " " << vect[1] << endl;
    }
}
