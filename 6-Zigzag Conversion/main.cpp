#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string convert(string s, int numRows)
    {

        if (numRows == 1)
        {
            return s;
        }
        unordered_set<int> visitedIndecies;
        string result;
        int maxJumps = 2 * (numRows - 1), rowCount = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (visitedIndecies.find(i) == visitedIndecies.end())
            {
                int j = i;
                int jump = (rowCount == 0 || rowCount == numRows - 1) ? (maxJumps - (2 * rowCount)) : maxJumps;
                while (j < s.size())
                {
                    cout<<  result<<endl;
                    cout << j << rowCount << jump << endl;
                    result.push_back(s[j]);
                    visitedIndecies.insert(j);
                    j += jump;
                }
                rowCount++;
            }
        }
        return result;
    }
};

int main()
{
    Solution s;
    s.convert("PAYPALISHIRING", 3);
}