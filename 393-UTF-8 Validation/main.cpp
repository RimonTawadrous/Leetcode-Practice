#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool validUtf8(vector<int> &data)
    {
        vector<int> numbers;
        int num;
        for (int i = 0; i < data.size(); i++)
        {
            num = data[i];
            if (i == 0)
            {
                num &= 0b11111000;
                num = num >> 3;
            }
            else
            {
                num &= 0b10000000;
                num = num >> 6;
            }
            numbers.push_back(num);
        }
        int bytesCount = 0;
        int count = 0;
        int headNumber = numbers[0];
        while (headNumber % 2 != 0)
        {
            headNumber = headNumber / 2;
            count++;
        }
        if (count == 5)
        {
            return false;
        }

        while (headNumber % 2 == 0 && headNumber != 0)
        {
            headNumber = headNumber / 2;
        }
        cout << headNumber << endl;
        switch (headNumber)
        {
        case 0:
            return true;
        case 3:
            bytesCount = 2;
            break;
        case 7:
            bytesCount = 3;
            break;
        case 15:
            bytesCount = 4;
            break;
        default:
            return false;
        }

        for (int i = 1; i < bytesCount; i++)
        {
            if (i >= numbers.size())
            {
                return false;
            }

            if (numbers[i] != 2)
            {
                return false;
            }
        }

        return true;
    }
};

int main()
{
    // vector<int> test = {197, 130, 1};
    // vector<int> test = {255};
    vector<int> test = {240, 162, 138, 147};

    Solution s;
    cout << s.validUtf8(test) << endl;
}