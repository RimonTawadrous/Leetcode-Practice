#include <bits/stdc++.h>
using namespace std;

class HitCounter
{
private:
    queue<long int> hitsTS;

public:
    HitCounter()
    {
    }

    void hit(int timestamp)
    {
        hitsTS.push(timestamp);

        while (!hitsTS.empty())
        {
            if (timestamp - hitsTS.front() > 300)
            {
                hitsTS.pop();
            }
            else
            {
                break;
            }
        }
    }

    int getHits(int timestamp)
    {
        while (!hitsTS.empty())
        {
            if (timestamp - hitsTS.front() > 300)
            {
                hitsTS.pop();
            }
            else
            {
                break;
            }
        }

        return hitsTS.size();
    }
};

int main()
{
}