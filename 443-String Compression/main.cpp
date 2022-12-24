#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int compress(vector<char> &chars)
    {
        int arrayIterator = 1, charsIterator = 0;
        char charToCompareWith = chars[0];
        int charRepeteionCount = 0;
        int totalCompresedCount = 0;

        while (charsIterator < chars.size())
        {
            charToCompareWith = chars[charsIterator];
            charRepeteionCount = 0;
            while (charsIterator < chars.size() && charToCompareWith == chars[charsIterator])
            {
                charRepeteionCount++;
                charsIterator++;
            }

            totalCompresedCount++;
            if (charRepeteionCount > 1)
            {
                vector<char> temp;
                while (charRepeteionCount > 10)
                {
                    temp.push_back((charRepeteionCount % 10) + '0');
                    charRepeteionCount = charRepeteionCount / 10;
                    totalCompresedCount++;
                }

                totalCompresedCount++;
                chars[arrayIterator] = charRepeteionCount + '0';
                arrayIterator++;

                reverse(temp.begin(), temp.end());
                for (char currentChar : temp)
                {
                    chars[arrayIterator] = currentChar;
                    arrayIterator++;
                }
            }
            if (arrayIterator < chars.size())
            {
                chars[arrayIterator] = chars[charsIterator];
            }
            arrayIterator++;
        }

        return totalCompresedCount;
    }
};

int main()
{
}