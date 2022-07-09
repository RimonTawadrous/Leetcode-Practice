#include <bits/stdc++.h>
using namespace std;

int findDuplicate(vector<int> &nums)
{
    int size = nums.size();
    int num = 0;
    int id;
    for (size_t i = 0; i < size; i++)
    {
        id = (nums[i] - 1) % size;
        nums[id] += size;
    }
    for (size_t i = 0; i < size; i++)
    {
        if (nums[i] > 2 * size)
        {
            num = i + 1;
        }
        nums[i] = nums[i] % size;
    }
    return num;
}

int main()
{
    vector<int> vector = {3, 1, 3, 4, 2};
    cout << findDuplicate(vector) << endl;
    return 0;
}