#include <bits/stdc++.h>
using namespace std;

bool isValid(string s)
{
    stack<char> parantethess;
    for (char currentChar : s)
    {
        switch (currentChar)
        {
        case ')':
            if (!parantethess.empty() && parantethess.top() == '(')
            {
                parantethess.pop();
            }
            else
            {
                return false;
            }
            break;
        case '}':
            if (!parantethess.empty() && parantethess.top() == '{')
            {
                parantethess.pop();
            }
            else
            {
                return false;
            }
            break;
        case ']':
            if (!parantethess.empty() && parantethess.top() == '[')
            {
                parantethess.pop();
            }
            else
            {
                return false;
            }
            break;
        default:
            parantethess.push(currentChar);
        }
    }
    if (!parantethess.empty())
    {
        return false;
    }
    return true;
}

int main()
{

    cout << isValid("") << endl;
    return 0;
}