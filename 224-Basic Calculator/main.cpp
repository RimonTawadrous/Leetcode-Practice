#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int solve(int &startIndex, string s)
    {
        int result = 0;

        while (startIndex < s.size() && s[startIndex] == ' ')
        {
            startIndex++;
        }
        cout << startIndex << endl;

        if (s[startIndex] >= '0' && s[startIndex] <= '9')
        {
            result = s[startIndex] - '0';
            startIndex++;
        }

        cout << "result = " << result << " " << startIndex << endl;
        while (startIndex < s.size())
        {
            switch (s[startIndex])
            {
            case ' ':
                break;
            case '(':
                startIndex++;
                result = solve(startIndex, s);
                break;
            case '+':
                cout << "+ = " << endl;
                startIndex++;
                result += solve(startIndex, s);
                break;
            case '-':
                startIndex++;
                result -= solve(startIndex, s);
                break;
            }
            startIndex++;
        }
        return result;
    }

public:
    int calculate(string s)
    {
        int i = 0;
        return solve(i, s);
    }
};

int main()
{
    Solution s;
    cout << s.calculate(" 2-1 + 2 ") << endl;
    return 0;
}