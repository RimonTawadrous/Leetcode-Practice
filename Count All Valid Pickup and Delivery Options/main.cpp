#include <bits/stdc++.h>
using namespace std;
int countOrders(int n)
{
    long int res = 1, modulo = 1000000007;
    for(int i=1; i<= n; i++){
        res = (res * i) % modulo;
        res = (res * (2*i-1)) % modulo;
    }
    return res % modulo;
}

int main()
{
    cout << countOrders(3) << endl;
}