#include <bits/stdc++.h>
using namespace std;

class Iterator
{
    struct Data;
    Data *data;

public:
    Iterator(const vector<int> &nums);
    Iterator(const Iterator &iter);
    // Returns the next element in the iteration.
    int next();
    // Returns true if the iteration has more elements.
    bool hasNext() const;
};

// class PeekingIterator : public Iterator
// {
// public:
//       // Returns the next element in the iteration without advancing the iterator.
//     int peek()
//     {
//         return Iterator(*this).next();
//     }
// };

class PeekingIterator : public Iterator
{
private:
    Iterator itr;
    int nextValue;

public:
    PeekingIterator(const vector<int> &nums) : Iterator(nums)
    {
        itr = Iterator(*this);
        if (hasNext())
        {
            nextValue = itr.next();
        }
        // Initialize any member here.
        // **DO NOT** save a copy of nums and manipulate it directly.
        // You should only use the Iterator interface methods.
    }

    // Returns the next element in the iteration without advancing the iterator.
    int peek()
    {
        return nextValue;
    }

    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    int next()
    {
        int val = nextValue;
        if (itr.hasNext())
        {
            nextValue = itr.next();
        }
        else
        {
            nextValue = NULL;
        }
        return val;
    }

    bool hasNext() const
    {
        return nextValue != NULL;
    }
};

int main()
{
}