#include <bits/stdc++.h>
using namespace std;

class BIT
{
public:
    int n;
    vector<int> tree;

    BIT(int n)
    {
        // the index: 0 is meaningless
        // the indices: [1,n] are meaningful
        // we can retrieve count of values from the tree
        this->n = n;
        tree = vector<int>(n + 1);
    }

    void increase(int i)
    {
        while (i <= n)
        {
            ++tree[i];
            // left child is covered by its parent
            // go to the upper node to its right
            i += i & -i;
        }
    }

    int get(int i)
    {
        // get count of numbers in [1, i]
        int count = 0;

        while (i > 0)
        {
            count += tree[i];
            // go to the upper node just to its left
            i -= i & -i;
        }

        return count;
    }
};

class Solution
{
public:
    vector<int> countSmaller(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n);
        if (n == 0)
            return ans;

        /*
        suppose nums's range is [a, b],
        convert it to [1, b-a+1]
        */
        int minv = *min_element(nums.begin(), nums.end());
        transform(nums.begin(), nums.end(), nums.begin(),
                  [&minv](int num)
                  { return num - minv + 1; });

        int maxv = *max_element(nums.begin(), nums.end());

        BIT *bit = new BIT(maxv);

        for (int i = n - 1; i >= 0; --i)
        {
            ans[i] = bit->get(nums[i] - 1);
            bit->increase(nums[i]);
        }

        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> test = {5, 2, 6, 1};
    vector<int> ans = s.countSmaller(test);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << "  ";
    }
}