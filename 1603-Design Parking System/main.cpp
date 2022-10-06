#include <bits/stdc++.h>
using namespace std;

class ParkingSystem
{
    vector<int> parkingSlots;

public:
    ParkingSystem(int big, int medium, int small)
    {
        parkingSlots.push_back(big);
        parkingSlots.push_back(medium);
        parkingSlots.push_back(small);
    }

    bool addCar(int carType)
    {
        if (parkingSlots[carType - 1] > 0)
        {
            parkingSlots[carType - 1]--;
            return true;
        }

        return false;
    }
};