#include <bits/stdc++.h>
using namespace std;

// class KthLargest
// {
// private:
//     priority_queue<int> stream;
//     int k;
//     int kLargest;
// public:
//     KthLargest(int k, vector<int> &nums)
//     {
//         this->k = k;
//         for (int number : nums)
//         {
//             stream.push(number);
//         }
//     }

//     int add(int val)
//     {
//         stream.push(val);
//         vector<int> temp;
//         int tempK = k;
//         int res;
//          if(kLargest > val){
//             return kLargest;
//         }
//         while (tempK > 1)
//         {
//             temp.push_back(stream.top());
//             stream.pop();
//             tempK--;
//         }
//         res = stream.top();
//         for (int number : temp)
//         {
//             stream.push(number);
//         }
//         return res;
//     }
// };

class KthLargest
{
private:
    priority_queue<int, vector<int>, greater<int>> stream;
    int k;

public:
    KthLargest(int k, vector<int> &nums)
    {
        this->k = k;
        int tempK = 0;
        for (int number : nums)
        {
            if (tempK < k)
            {

                stream.push(number);
                tempK++;
            }
            else
            {
                if (number > stream.top())
                {
                    stream.pop();
                    stream.push(number);
                }
            }
        }
    }

    int add(int val)
    {
        if (stream.size() < k)
        {
            stream.push(val);
        }
        else if (val > stream.top())
        {
            stream.pop();
            stream.push(val);
        }
        return stream.top();
    }
};

int main()
{
    vector<int> nums = {4, 5, 8, 2};
    int k = 3;
    KthLargest kthLargest(k, nums);
    cout << kthLargest.add(3) << endl;
    cout << kthLargest.add(5) << endl;
    cout << kthLargest.add(10) << endl;
    cout << kthLargest.add(9) << endl;
    cout << kthLargest.add(4) << endl;
}