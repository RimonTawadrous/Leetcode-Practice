#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int lastIndex = m + n - 1;
    m--;
    n--;

    while (m >= 0 && n >= 0)
    {
        if (nums1[m] > nums2[n])
        {
            nums1[lastIndex--] = nums1[m--];
        }
        else
        {
            nums1[lastIndex--] = nums2[n--];
        }
    }
    if (m < 0)
    {
        while (n >= 0)
        {
            nums1[lastIndex--] = nums2[n--];
        }
    }
    else if (n < 0)
    {
        while (m >= 0)
        {
            nums1[lastIndex--] = nums1[m--];
        }
    }
}

int main()
{
    vector<int> num1 = {1, 2, 3, 0, 0, 0};
    vector<int> num2 = {2, 5, 6};

    merge(num1, 3, num2,3);

    for (auto val : num1)
    {
        cout << val << " ";
    }
}