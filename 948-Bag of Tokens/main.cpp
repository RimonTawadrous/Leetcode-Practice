#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int bagOfTokensScore(vector<int> &tokens, int power)
    {
        sort(tokens.begin(), tokens.end());
        int start = 0, end = tokens.size() - 1;
        int score = 0;
        while (start <= end)
        {
            if (power >= tokens[start])
            {
                power -= tokens[start];
                score++;
                start++;
            }
            else if (score > 0 && start != end)
            {
                power += tokens[end];
                end--;
                score--;
            }
            else
            {
                break;
            }
        }
        return score;
    }
};

int main()
{
}