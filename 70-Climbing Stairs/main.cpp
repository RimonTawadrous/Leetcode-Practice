#include <bits/stdc++.h>
using namespace std;

int climbStairs(int n)
{
    if (n == 0)
    {
        return 0;
    }
    int prev = 1, prevPrev = 1, current = 1;

    for (int i = 2; i < n + 1; i++)
    {
        current = prev + prevPrev;
        prevPrev = prev;
        prev = current;
    }
    return current;
}

int main()
{
}