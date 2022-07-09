#include <bits/stdc++.h>
using namespace std;

class FreqStack
{
private:
    unordered_map<int, vector<int>> stacks;
    unordered_map<int, int> elementsCount;
    int maxCount = 0;

public:
    FreqStack()
    {
        maxCount = 0;
    }

    void push(int val)
    {
        int count = 1;
        if (elementsCount.find(val) != elementsCount.end())
        {
            count = elementsCount[val] + 1;
        }
        elementsCount[val] = count;

        if (count > maxCount)
        {
            maxCount = count;
            stacks[count] = {};
        }
        stacks[count].push_back(val);
    }

    int pop()
    {
        if (stacks.find(maxCount) == stacks.end())
        {
            return -1;
        }

        int val = stacks[maxCount][stacks[maxCount].size() - 1];
        stacks[maxCount].pop_back();
        elementsCount[val]--;
        while (!stacks[maxCount].size() && maxCount > 0)
        {
            maxCount--;
        }

        return val;
    }
};

int main()
{
    FreqStack freqStack;
    freqStack.push(5);               // The stack is [5]
    freqStack.push(7);               // The stack is [5,7]
    freqStack.push(5);               // The stack is [5,7,5]
    freqStack.push(7);               // The stack is [5,7,5,7]
    freqStack.push(4);               // The stack is [5,7,5,7,4]
    freqStack.push(5);               // The stack is [5,7,5,7,4,5]
    cout << freqStack.pop() << endl; // return 5, as 5 is the most frequent. The stack becomes [5,7,5,7,4].
    cout << freqStack.pop() << endl; // return 7, as 5 and 7 is the most frequent, but 7 is closest to the top. The stack becomes [5,7,5,4].
    cout << freqStack.pop() << endl; // return 5, as 5 is the most frequent. The stack becomes [5,7,4].
    cout << freqStack.pop() << endl; // return 4, as 4, 5 and 7 is the most frequent, but 4 is closest to the top. The stack becomes [5,7].

    return 0;
}