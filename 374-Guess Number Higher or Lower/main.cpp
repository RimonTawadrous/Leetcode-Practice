#include <bits/stdc++.h>
using namespace std;

int guess(int num);

class Solution
{
public:
    int guessNumber(int n)
    {
        int low = 1, high = n, current = low + (high - low) / 2;
        int guessResult = 0;
        do
        {
            current = low + (high - low) / 2;
            guessResult = guess(current);
            switch (guess(current))
            {
            case 1:
                low = current + 1;
                break;
            case -1:
                high = current - 1;
                break;
            case 0:
                return current;
            }
        } while (guessResult != 0);
    }
};

int main()
{
}