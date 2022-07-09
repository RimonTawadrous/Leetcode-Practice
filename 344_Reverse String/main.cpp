#include <bits/stdc++.h>
using namespace std;

void reverseString(vector<char> &s)
{
    int i = 0, j = s.size()-1;
    char temp;
    while (i < j)
    {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        i++;
        j--;
    }
}

int main()
{
    vector<char> s = {'R', 'i', 'm', 'o', 'n'};
    reverseString(s);
    for (size_t i = 0; i < s.size(); i++)
    {
        cout<< s[i] << " "; 
    }
}