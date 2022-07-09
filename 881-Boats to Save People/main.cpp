#include <bits/stdc++.h>
using namespace std;

int numRescueBoats(vector<int> &people, int limit)
{
    unordered_map<int, int> weightFreq;
    int count = 0;

    sort(people.begin(), people.end());
    int i = 0, j = people.size() - 1;
    while (i <= j)
    {
        if (people[j] <= limit)
        {
            if (people[j] + people[i] <= limit)
            {
                i++;
            }
            count++;
        }

        j--;
    }
    return count;
}

int main()
{
    vector<int> people = {3, 5, 3, 4};
    cout << numRescueBoats(people, 3) << endl;
    return 0;
}