#include <bits/stdc++.h>
using namespace std;

string addBinary(string a, string b)
{
    if (b.size() > a.size())
    {
        return addBinary(b, a);
    }

    int carry = 0, result = 0, aDiff = a.size() - b.size();

    string ans;

    for (int i = b.size() - 1; i > -1; i--)
    {

        if (a[aDiff + i] == '1' && b[i] == '1')
        {
            if (carry)
            {
                ans.push_back('1');
            }
            else
            {
                ans.push_back('0');
            }
            carry = 1;
        }
        else if (a[aDiff + i] == '1' && b[i] == '0')
        {
            if (carry)
            {
                ans.push_back('0');
                carry = 1;
            }
            else
            {
                ans.push_back('1');
                carry = 0;
            }
        }
        else if (a[aDiff + i] == '0' && b[i] == '1')
        {
            if (carry)
            {
                ans.push_back('0');
                carry = 1;
            }
            else
            {
                ans.push_back('1');
                carry = 0;
            }
        }
        else if (a[aDiff + i] == '0' && b[i] == '0')
        {
            if (carry)
            {
                ans.push_back('1');
            }
            else
            {
                ans.push_back('0');
            }
            carry = 0;
        }
    }

    for (int i = a.size() - b.size() - 1; i > -1; i--)
    {
        if (carry)
        {
            if (a[i] == '1')
            {
                ans.push_back('0');
                carry = 1;
            }
            else
            {
                ans.push_back('1');
                carry = 0;
            }
        }
        else
        {
            ans.push_back(a[i]);
        }
    }
    if (carry)
    {
        ans.push_back('1');
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    cout << addBinary("10001", "1111") << endl;
}