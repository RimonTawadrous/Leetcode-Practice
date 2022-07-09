#include <bits/stdc++.h>
using namespace std;

int minDominoRotations(vector<int> &tops, vector<int> &bottoms)
{
    int firstNumber = tops[0];
    int secondNumber = bottoms[0];
    int minNumber = INT_MAX;
    int topRotations = 0;
    int bottomRotations = 0;

    for (size_t i = 0; i < tops.size(); i++)
    {
        if (tops[i] != firstNumber)
        {
            if (bottoms[i] != firstNumber)
            {
                topRotations = -1;
                break;
            }
            else
            {
                topRotations++;
            }
        }
    }
    for (size_t i = 0; i < tops.size(); i++)
    {
        if (bottoms[i] != firstNumber)
        {
            if (tops[i] != firstNumber)
            {
                bottomRotations = -1;
                break;
            }
            else
            {
                bottomRotations++;
            }
        }
    }
    if (topRotations >= 0 && bottomRotations >= 0)
    {
        minNumber = min(topRotations, bottomRotations);
    }
    else if (topRotations >= 0)
    {
        minNumber = topRotations;
    }
    else if (bottomRotations >= 0)
    {
        minNumber = bottomRotations;
    }

    if (firstNumber == secondNumber)
    {
        return minNumber == INT_MAX ? -1 : minNumber;
    }

    topRotations = 0;
    bottomRotations = 0;

    for (size_t i = 0; i < tops.size(); i++)
    {
        if (tops[i] != secondNumber)
        {
            if (bottoms[i] != secondNumber)
            {
                topRotations = -1;
                break;
            }
            else
            {
                cout << "yes" << endl;
                topRotations++;
            }
        }
    }

    for (size_t i = 0; i < tops.size(); i++)
    {
        if (bottoms[i] != secondNumber)
        {
            if (tops[i] != secondNumber)
            {
                bottomRotations = -1;
                break;
            }
            else
            {
                bottomRotations++;
            }
        }
    }
    int tempMin = INT_MAX;
    if (topRotations >= 0 && bottomRotations >= 0)
    {
        tempMin = min(topRotations, bottomRotations);
    }
    else if (topRotations >= 0)
    {
        tempMin = topRotations;
    }
    else if (bottomRotations >= 0)
    {
        tempMin = bottomRotations;
    }

    minNumber = min(minNumber, tempMin);

    return minNumber == INT_MAX ? -1 : minNumber;
}

int main()
{
    // vector<int> tops = {2, 1, 2, 4, 2, 2};
    // vector<int> bottoms = {5, 2, 6, 2, 3, 2};

    // vector<int> tops = {3, 5, 1, 2, 3};
    // vector<int> bottoms = {3, 6, 3, 3, 4};

    vector<int> tops = {1, 2, 1, 1, 1, 2, 2, 2};
    vector<int> bottoms = {2, 1, 2, 2, 2, 2, 2, 2};

    cout << minDominoRotations(tops, bottoms) << endl;
}