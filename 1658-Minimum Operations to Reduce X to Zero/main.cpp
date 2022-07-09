#include <bits/stdc++.h>
using namespace std;

int minOperations(vector<int> &nums, int x)
{
    map<int, vector<int>> map;
    int minOperationsCounts = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        map[i].push_back(nums[i]);
    }

    return minOperationsCounts;
}

//   int minOperations(vector<int>& nums, int x) {
//         int n = nums.size();
//         int sum = 0;
//         unordered_map<int,int> mymap;   //<sum,pos>
//         for(int i=0;i<n;++i)
//         {
//             sum+=nums[i];
//             mymap[sum] = i;
//         }
//         if(x>sum)   //Sum out of range
//             return -1;
//         mymap[0] = 0;

//         int longest = 0;
//         sum-=x;
//         int val = 0;
//         for(int i=0;i<n;++i)
//         {
//             val += nums[i];
//             if(mymap.count(val-sum))
//             {
//                 if(val-sum==0)
//                     longest = max(longest,i-mymap[val-sum]+1);
//                 else
//                     longest = max(longest,i-mymap[val-sum]);
//             }
//         }
//         return longest==0?(sum==0?n:-1):n-longest;
//     }

int minOperations(vector<int> &nums, int x)
{
    int sum = 0;
    unordered_map<int, int> mymap; //<sum,pos>
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        mymap[sum] = i;
    }

    

}

int main()
{
}