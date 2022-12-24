#include <bits/stdc++.h>
using namespace std;

class StockSpanner
{
private:
    stack<pair<int, int>> priceStack;

public:
    StockSpanner()
    {
    }

    int next(int price)
    {
        int pricesLowerThanInputPriceCount = 1;
        while (!priceStack.empty() && priceStack.top().first <= price)
        {
            pricesLowerThanInputPriceCount += priceStack.top().second;
            priceStack.pop();
        }
        priceStack.push(make_pair(price, pricesLowerThanInputPriceCount));
        return pricesLowerThanInputPriceCount;
    }
};

int main()
{
}