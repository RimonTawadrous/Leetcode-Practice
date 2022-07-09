#include <bits/stdc++.h>
using namespace std;

int minPartitions(string n)
{
    char maxnumber = '0';
    for (int i = 0; i < n.size(); i++)
    {
        if (n[i] > maxnumber)
        {
            maxnumber = n[i];
        }
    }
    return maxnumber - '0';
}