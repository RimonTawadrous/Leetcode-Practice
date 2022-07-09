#include <bits/stdc++.h>
#include <string>
#include <sstream>

using namespace std;
int calPoints(vector<string> &ops)
{
    vector<int> vals;
    int num = 0;
    stringstream ss;

    for (size_t i = 0; i < ops.size(); i++)
    {
        num = 0;
        if (ops[i] == "+")
        {
            vals.push_back(vals[vals.size() - 1] + vals[vals.size() - 2]);
        }
        else if (ops[i] == "C")
        {
            vals.pop_back();
        }
        else if (ops[i] == "D")
        {
            vals.push_back(vals[vals.size() - 1] * 2);
        }
        else
        {
            sscanf(ops[i].c_str(), "%d", &num);
            vals.push_back(num);
        }
    }
    int sum = 0;
    for (int currentVal : vals)
    {
        sum += currentVal;
    }

    return sum;
}

int main()
{
    // vector<string> ops = {"5", "2", "C", "D", "+"};
    vector<string> ops = {"5", "-2", "4", "C", "D", "9", "+", "+"};

    cout << calPoints(ops) << endl;
}