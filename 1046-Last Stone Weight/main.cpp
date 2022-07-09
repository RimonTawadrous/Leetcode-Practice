#include <bits/stdc++.h>
using namespace std;

int lastStoneWeight(vector<int> &stones)
{
    make_heap(stones.begin(), stones.end());
    priority_queue<int> stonesQ(stones.begin(), stones.end());

    // for (size_t i = 0; i < stones.size(); i++)
    // {
    //     stonesQ.push(stones[i]);
    // }
    int firstStone;
    int secondStone;
    while (stonesQ.size() > 1)
    {
        firstStone = stonesQ.top();
        stonesQ.pop();
        secondStone = stonesQ.top();
        stonesQ.pop();
        stonesQ.push(firstStone - secondStone);
    }
    if (stonesQ.size() > 0)
    {
        return stonesQ.top();
    }
    return 0;
}

int main()
{
    vector<int> stones = {2, 7, 4, 1, 8, 1};
    cout << lastStoneWeight(stones) << endl;
}