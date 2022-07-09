#include <bits/stdc++.h>
using namespace std;

bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
{
    stack<int> tempstack;
    int pushIndex = 0;
    int poppedIndex = 0;
    int pushedSize = pushed.size();
    int popedSize = popped.size();

    while (pushIndex < pushedSize)
    {
        tempstack.push(pushed[pushIndex]);
        while (!tempstack.empty() && popped[poppedIndex] == tempstack.top()  )
        {
            tempstack.pop();
            poppedIndex++;
        }
        pushIndex++;
    }
    while (poppedIndex < popedSize && !tempstack.empty())
    {
        if (popped[poppedIndex] != tempstack.top())
        {
            return false;
        }
        tempstack.pop();
        poppedIndex++;
    }

    if (!tempstack.empty())
    {
        return false;
    }
    return true;
}

int main()
{
    vector<int> pushed = {1, 2, 3, 4, 5};
    vector<int> popped = {4, 5, 3, 2, 1};

    cout << validateStackSequences(pushed, popped) << endl;
    return 0;
}