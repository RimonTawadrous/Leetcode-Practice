#include <bits/stdc++.h>
using namespace std;

// string minRemoveToMakeValid(string s)
// {
//     stack<char> parentheses;
//     stack<int> parenthesesplace;
//     unordered_set<int> places;
//     string res;
//     int size = s.size();
//     for (int i = 0; i < size; i++)
//     {
//         switch (s[i])
//         {
//         case ')':
//             if (!parentheses.empty() && parentheses.top() == '(')
//             {
//                 parentheses.pop();
//                 parenthesesplace.pop();
//             }
//             else
//             {
//                 parentheses.push(')');
//                 parenthesesplace.push(i);
//             }
//             break;
//         case '(':
//             parentheses.push('(');
//             parenthesesplace.push(i);
//             break;
//         }
//     }
//     while (!parenthesesplace.empty())
//     {
//         places.insert(parenthesesplace.top());
//         parenthesesplace.pop();
//     }
//     for (int i = 0; i < size; i++)
//     {
//         if (places.find(i) == places.end()){
//             res.push_back(s[i]);
//         }
//     }
//     return res;
// }

string minRemoveToMakeValid(string s)
{
    string temp;
    string res = "";
    int open = 0;
    int size = s.size();
    for (int i = 0; i < size; i++)
    {
        switch (s[i])
        {
        case ')':
            if (open > 0)
            {
                open--;
            }
            else
            {
                continue;
            }
            break;
        case '(':
            open++;
            break;
        }

        temp.push_back(s[i]);
    }

    for (int i = temp.size() - 1; i > -1; i--)
    {
        if (temp[i] == '(' && open-- > 0)
        {
            continue;
        }
        res.push_back(temp[i]);
    }
    if (res.size())
    {
        reverse(res.begin(), res.end());
    }

    return res;
}

int main()
{
    cout << minRemoveToMakeValid("))((") << endl;
    return 0;
}