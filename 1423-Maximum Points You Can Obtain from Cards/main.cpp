#include <bits/stdc++.h>
using namespace std;

int maxScore(vector<int> &cardPoints, int k)
{
    int leftSum = 0, rightSum = 0, leftOuter = 0, leftInner = k - 1, rightOuter = cardPoints.size() - 1, rightInner = cardPoints.size() - k;
    int score = 0;
    for (int i = 0; i < k; i++)
    {
        leftSum += cardPoints[i];
    }
    for (int i = cardPoints.size() - 1; i > cardPoints.size() - 1 - k; i--)
    {
        rightSum += cardPoints[i];
    }

    while (k > 0)
    {
        if (leftSum >= rightSum)
        {
            // cout << "left" << cardPoints[leftOuter] << " ";
            score += cardPoints[leftOuter];
            leftSum -= cardPoints[leftOuter];
            rightSum -= cardPoints[rightInner];
            leftOuter++;
            rightInner++;
        }
        else
        {
            // cout << "right" << cardPoints[rightOuter] << " ";
            score += cardPoints[rightOuter];
            rightSum -= cardPoints[rightOuter];
            leftSum -= cardPoints[leftInner];
            rightOuter--;
            leftInner--;
        }
        k--;
    }

    return score;
}

int main()
{

    // vector<int> test = {1, 2, 3, 4, 5, 6, 1};
    // vector<int> test = {9, 7, 7, 9, 7, 7, 9};
    vector<int> test = {96, 90, 41, 82, 39, 74, 64, 50, 30};

    cout << maxScore(test, 8) << endl;
}