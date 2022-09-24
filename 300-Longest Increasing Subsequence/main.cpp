#include <bits/stdc++.h>
using namespace std;

int lengthOfLIS(vector<int> &nums)
{
    vector<int> db(nums.size(), 1);
    int returnNumber = 0;
    for (int i = nums.size() - 1; i > -1; i--)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[i] < nums[j])
            {
                db[i] = max(db[i], 1 + db[j]);
            }
        }
    }

    for (int i = 0; i < db.size(); i++)
    {
        if (returnNumber < db[i])
        {
            returnNumber = db[i];
        }
    }
    return returnNumber;
}

int main()
{
    vector<int> test = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << lengthOfLIS(test) << endl;
}