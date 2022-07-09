#include <bits/stdc++.h>
using namespace std;

int scheduleCourse(vector<vector<int>> &courses)
{
    auto cmp = [](const pair<int, int> &lhs, const pair<int, int> &rhs)
    {
        return lhs.second > rhs.second;
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
    priority_queue<int> values;

    for (vector<int> course : courses)
    {
        pq.push(make_pair(course[0], course[1]));
    }
    int time = 0;
    int count = 0;
    while (!pq.empty())
    {
        pair<int, int> currentCousre = pq.top();
        pq.pop();
        if (time + currentCousre.first <= currentCousre.second)
        {
            time += currentCousre.first;
            count++;
            values.push(currentCousre.first);
        }
        else if (!values.empty() && values.top() > currentCousre.first)
        {
            int tempTime = time - values.top();
            if (tempTime + currentCousre.first <= currentCousre.second)
            {
                values.pop();
                values.push(currentCousre.first);
                time = tempTime + currentCousre.first;
            }
        }
        // cout << "( " << temp.first << " , " << temp.second << " )" << endl;
    }
    return count;
}

int main()
{
    // vector<vector<int>> test = {{100, 200}, {200, 1300}, {1000, 1250}, {2000, 3200}};
    vector<vector<int>> test = {{5, 5}, {4, 6}, {2, 6}};

    cout << scheduleCourse(test);
}