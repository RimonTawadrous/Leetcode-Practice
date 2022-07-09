#include <bits/stdc++.h>
using namespace std;
#include <stdio.h>

vector<int> countBits(int n)
{
    vector<int> numberOfOnesArray(n + 1);

    int number_of_bits = 1;
    int number_of_ones = 0;

    for (int i = 1; i < n + 1; i++)
    {
        // if(number_of_bits == number_of_ones){
        //     number_of_bits++;
        //     number_of_ones = 1;
        //     numberOfOnesArray[i] = number_of_ones;

        // }else{
        //     number_of_ones++;
        //     numberOfOnesArray[i] = number_of_ones;
        // }
        numberOfOnesArray[i] = __builtin_popcount(i);
    }
    return numberOfOnesArray;
}

int main()
{
    countBits(15);
    return 0;
}