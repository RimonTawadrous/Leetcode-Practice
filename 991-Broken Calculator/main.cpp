#include <bits/stdc++.h>
using namespace std;
int brokenCalc(int startValue, int target)
{
    if (startValue > target || startValue == target)
    {
        return startValue - target;
    }
    int halfTheValue = target / 2;
    int count = 0;
    int v = startValue;

    while (v < target)
    {
        if(target % 2 == 0 ){
            target = target / 2;
        }else{
            target = target + 1;
        }
        count++;
        cout << count << endl;
    } 
 
    if(startValue > target){
        count += startValue - target;

    }

    return count;
}


int main()
{
    cout << " value  = " << brokenCalc(1, 1000000000) << endl;
}