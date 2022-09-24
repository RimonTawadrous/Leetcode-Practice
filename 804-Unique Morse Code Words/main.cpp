#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int uniqueMorseRepresentations(vector<string> &words)
    {
        vector<string> map = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
        unordered_set<string> morseCodes;
        string tempString;
        for (string word : words)
        {
            tempString = "";
            for (char c : word)
            {
                tempString += map[c - 'a'];
            }
            morseCodes.insert(tempString);
        }
        return morseCodes.size();
    }
};

int main()
{
}