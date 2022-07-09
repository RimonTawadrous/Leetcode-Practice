#include <bits/stdc++.h>
using namespace std;

int threeSumMulti(vector<int> &arr, int target)
{
    vector<long> freq(101, 0);
    int mod = 1000000007;
    long int result = 0;
    for (size_t i = 0; i < arr.size(); i++)
    {
        freq[arr[i]]++;
    }
    for (size_t i = 0; i < 101; i++)
    {
        for (size_t j = i; j < 101; j++)
        {

            int reminder = target - i - j;
            long val = 0;
            if (reminder < 0 || reminder > 100 || reminder < j || reminder < i)
            {
                continue;
            }
            if (freq[i] == 0 || freq[j] == 0 || freq[reminder] == 0)
            {
                continue;
            }
            if (i == j && i == reminder)
            {
                result = (result + (freq[i] * (freq[i] - 1) * (freq[i] - 2)) / 6) % mod;
            }
            else if (i == j)
            {
                result = (result + ((freq[i] * (freq[i] - 1)) / 2) * freq[reminder]) % mod;
            }
            else if (j == reminder)
            {
                result = (result + ((freq[j] * (freq[j] - 1)) / 2) * freq[i]) % mod;
            }
            else if (i != j && i != reminder)
            {
                result = (result + freq[i] * freq[j] * freq[reminder]) % mod;
            }
            result += val;
            result = result % mod;

            // cout << "( " << i << " , " << j << " , " << reminder << " )"
            //      << " r = " << val << endl;
        }
    }
    return result;
}

int main()
{
    vector<int> arr = {1, 1, 2, 2, 3, 3, 4, 4, 5, 5};
    int target = 8;
    // vector<int> arr = {1, 1, 2, 2, 2, 2};
    // int target = 5;
    cout << threeSumMulti(arr, target) << endl;
}
