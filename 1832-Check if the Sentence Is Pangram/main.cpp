#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkIfPangram(string sentence)
    {
        vector<int> alphabets(26, 0);
        for (char charachter : sentence)
        {
            alphabets[charachter - 'a']++;
        }
        for (int charchterCount : alphabets)
        {
            if (charchterCount == 0)
            {
                return false;
            }
        }

        return true;
    }
};

int main()
{
}