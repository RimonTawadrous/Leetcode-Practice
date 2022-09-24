#include <bits/stdc++.h>
using namespace std;

// class Solution
// {
// private:
//     vector<int> count(int number)
//     {
//         vector<int> array(10, 0);
//         while (number > 0)
//         {
//             array[number % 10]++;
//             number /= 10;
//         }
//         return array;
//     }

// public:
//     bool reorderedPowerOf2(int n)
//     {
//         vector<int> numberCounts = count(n);
//         int num = 1;
//         for (size_t i = 0; i < 31; i++)
//         {
//             if (numberCounts == count(num))
//             {
//                 return true;
//             }

//             num = num << 1;
//         }

//         return false;
//     }
// };

// early termination
class Solution
{
private:
    vector<int> count(int number)
    {
        vector<int> array(10, 0);
        while (number > 0)
        {
            array[number % 10]++;
            number /= 10;
        }
        return array;
    }

    int maxBits(int number)
    {
        vector<int> array(10, 0);
        while (number > 0)
        {
            array[number % 10]++;
            number /= 10;
        }

        int num = 0;
        int bits = 0;

        for (int i = 9; i > -1; i--)
        {
            for (size_t j = 1; j <= array[i]; j++)
            {
                num *= 10;
                num += i;
            }
        }
        while (num)
        {
            bits++;
            num >>= 1;
        }
        return bits;
    }

public:
    bool reorderedPowerOf2(int n)
    {
        vector<int> numberCounts = count(n);
        int bits = maxBits(n);
        int num = 1;
        for (size_t i = 0; i < bits; i++)
        {
            if (numberCounts == count(num))
            {
                return true;
            }

            num = num << 1;
        }

        return false;
    }
};

int main()
{
    Solution s;
    s.reorderedPowerOf2(10);
}