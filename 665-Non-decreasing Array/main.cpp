#include <bits/stdc++.h>
using namespace std;

// bool checkPossibility(vector<int> &nums)
// {
//     bool isChanged = false;
//     for (int i = 0; i < nums.size(); i++)
//     {

//         if(nums[i] <= nums[i+1]){
//             continue;
//         }
//         if(isChanged){
//             return false;
//         }

//         if(i==0 || nums[i+1] >= nums[i-1]){
//             nums[i] = nums[i+1];
//             cout<< "yes";
//         }else{
//             nums[i+1] = nums[i];
//         }
//         isChanged = true;
//     }

//     return true;
// }

bool checkPossibility(vector<int> &nums)
{
    bool isChanged = false;
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i - 1] > nums[i])
        {
            if (isChanged)
            {
                return false;
            }
            else
            {
                if (i < nums.size() - 1 && nums[i - 1] <= nums[i + 1] || i == nums.size() - 1)
                {
                    nums[i] = nums[i - 1];
                }
                else
                {
                    nums[i - 1] = nums[i];
                }

                isChanged = true;
            }
        }
    }

    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i - 1] > nums[i])
        {
            return false;
        }
    }

    return true;
}

int main()
{
}