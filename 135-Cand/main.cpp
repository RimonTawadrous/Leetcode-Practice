#include <bits/stdc++.h>
using namespace std;

int candy(vector<int> &ratings)
{
    int count = 0, prevCount = 1, tempPrevCount = 0, k = 0;
    if (ratings.size() > 1 && ratings[0] > ratings[1])
    {
        tempPrevCount = 1;
        while ((k + 1 < ratings.size()) && (ratings[k] > ratings[k + 1]))
        {
            tempPrevCount++;
            count += tempPrevCount;
            k++;
        }
        prevCount = tempPrevCount;
    }
    else
    {
        count++;
    }
    k = k > 1 ? k : 1;
    for (int i = k; i < ratings.size(); i++)
    {
        if (ratings[i] > ratings[i - 1])
        {
            prevCount++;
            count += prevCount;
        }
        else if (ratings[i] == ratings[i - 1] || (i + 1 < ratings.size()) && (ratings[i] > ratings[i + 1]))
        {
            tempPrevCount = 1;
            count++;
            int j = i - 1;
            while ((i + 1 < ratings.size()) && (ratings[i] > ratings[i + 1]))
            {
                tempPrevCount++;
                count += tempPrevCount;
                i++;
            }

            if (prevCount <= tempPrevCount)
            {
                while ((j > 0) && (ratings[j] > ratings[j + 1]))
                {
                    count += tempPrevCount - prevCount + 1;
                    j--;
                }
            }
            prevCount = 1;
        }
        else
        {
            prevCount = 1;
            count++;
        }
    }
    return count;
}

int main(){}

    [1, 0, 2]
    [1, 2, 87, 87, 87, 2, 1]
    [1, 3, 2, 2, 1]
    [1, 6, 10, 8, 7, 3, 2]
    [0, 1, 2, 5, 3, 2, 7]
    [1, 2, 3, 5, 4, 3, 2, 1]
    [1, 2, 3, 5, 4, 3, 2, 1, 4, 3, 2, 1]