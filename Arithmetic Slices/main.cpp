#include <bits/stdc++.h>
using namespace std;
#include <stdio.h>

int numberOfArithmeticSlices(vector<int> &nums)
{
    if (nums.size() < 3)
    {
        return 0;
    }
    int diff = 0, numbersOfArithmetic = 0, numberOfconsecutiveEqualDiff = 0;

    for (size_t i = 1; i < nums.size(); i++)
    {
        if (diff == nums[i] - nums[i - 1])
        {
            numberOfconsecutiveEqualDiff++;
        }
        else
        {
            if (numberOfconsecutiveEqualDiff >= 2)
            {
                numbersOfArithmetic += (numberOfconsecutiveEqualDiff * (numberOfconsecutiveEqualDiff - 1)) / 2;
            }
            diff = nums[i] - nums[i - 1];
            numberOfconsecutiveEqualDiff = 1;
        }
    }
    if (numberOfconsecutiveEqualDiff >= 2)
    {
        numbersOfArithmetic += (numberOfconsecutiveEqualDiff * (numberOfconsecutiveEqualDiff - 1)) / 2;
    }

    return numbersOfArithmetic;
}

int numberOfArithmeticSlices(vector<int> &nums)
{
    if (nums.size() < 3)
    {
        return 0;
    }
    int numbersOfArithmetic = 0, numberOfconsecutiveEqualDiff = 0;

    for (size_t i = 2; i < nums.size(); i++)
    {
        if (nums[i] - nums[i-1] == nums[i-1] - nums[i - 2])
        {
            numberOfconsecutiveEqualDiff++;
        }
        else
        {
            numbersOfArithmetic += (numberOfconsecutiveEqualDiff * (numberOfconsecutiveEqualDiff + 1)) / 2;
            numberOfconsecutiveEqualDiff = 0;
        }
    }
    numbersOfArithmetic += (numberOfconsecutiveEqualDiff * (numberOfconsecutiveEqualDiff + 1)) / 2;
    return numbersOfArithmetic;
}

int main()
{
    vector<int> v = {1,2,3,4};
    numberOfArithmeticSlices(v);
    return 0;
}