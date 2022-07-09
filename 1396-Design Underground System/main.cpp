#include <bits/stdc++.h>
using namespace std;

class UndergroundSystem
{
    struct trip
    {
        int id;
        string start;
        int startTime;
        int endTime;

        trip(int id, string start, int startTime, int endTime) : id(id), start(start), startTime(startTime), endTime(endTime)
        {
        }
    };

    map<int, pair<string, int>> checkIns;
    map<string, vector<trip>> trips;

public:
    UndergroundSystem()
    {
    }

    void checkIn(int id, string stationName, int t)
    {
        checkIns[id] = make_pair(stationName, t);
    }

    void checkOut(int id, string stationName, int t)
    {
        if (checkIns.find(id) != checkIns.end())
        {
            trip tempTrip(id, checkIns[id].first, checkIns[id].second, t);
            trips[stationName].push_back(tempTrip);
        }
    }

    double getAverageTime(string startStation, string endStation)
    {
        double value = 0.0;
        int count = 0;
        if (trips.find(endStation) == trips.end())
        {
            return value;
        }
        for (trip currentTrip : trips[endStation])
        {
            if (currentTrip.start == startStation)
            {
                count++;
                value += currentTrip.endTime - currentTrip.startTime;
            }
        }
        return (double)(value / (double)count);
    }
};

int main()
{
    UndergroundSystem undergroundSystem;

    // undergroundSystem.checkIn(45, "Leyton", 3);
    // undergroundSystem.checkIn(32, "Paradise", 8);
    // undergroundSystem.checkIn(27, "Leyton", 10);
    // undergroundSystem.checkOut(45, "Waterloo", 15);            // Customer 45 "Leyton" -> "Waterloo" in 15-3 = 12
    // undergroundSystem.checkOut(27, "Waterloo", 20);            // Customer 27 "Leyton" -> "Waterloo" in 20-10 = 10
    // undergroundSystem.checkOut(32, "Cambridge", 22);           // Customer 32 "Paradise" -> "Cambridge" in 22-8 = 14
    // undergroundSystem.getAverageTime("Paradise", "Cambridge"); // return 14.00000. One trip "Paradise" -> "Cambridge", (14) / 1 = 14
    // undergroundSystem.getAverageTime("Leyton", "Waterloo");    // return 11.00000. Two trips "Leyton" -> "Waterloo", (10 + 12) / 2 = 11
    // undergroundSystem.checkIn(10, "Leyton", 24);
    // undergroundSystem.getAverageTime("Leyton", "Waterloo"); // return 11.00000
    // undergroundSystem.checkOut(10, "Waterloo", 38);         // Customer 10 "Leyton" -> "Waterloo" in 38-24 = 14
    // double test = undergroundSystem.getAverageTime("Leyton", "Waterloo"); // return 12.00000. Three trips "Leyton" -> "Waterloo", (10 + 12 + 14) / 3 = 12

    undergroundSystem.checkIn(596854, "EQH524YN", 13);
    undergroundSystem.checkIn(29725, "Y1A2ROGU", 17);
    undergroundSystem.checkOut(596854, "8AYN1B7O", 115);
    undergroundSystem.checkIn(579716, "EQH524YN", 145);
    undergroundSystem.checkOut(579716, "8AYN1B7O", 199);
    undergroundSystem.checkOut(29725, "8AYN1B7O", 295);
    undergroundSystem.checkIn(939079, "16MTS56Z", 371);
    double test1 = undergroundSystem.getAverageTime("EQH524YN", "8AYN1B7O"); // return 12.00000. Three trips "Leyton" -> "Waterloo", (10 + 12 + 14) / 3 = 12
    double test2 = undergroundSystem.getAverageTime("Y1A2ROGU", "8AYN1B7O"); // return 12.00000. Three trips "Leyton" -> "Waterloo", (10 + 12 + 14) / 3 = 12
    undergroundSystem.checkIn(697035, "EQH524YN", 442);
    undergroundSystem.checkIn(90668, "Y1A2ROGU", 508);
    double test3 = undergroundSystem.getAverageTime("EQH524YN", "8AYN1B7O"); // return 12.00000. Three trips "Leyton" -> "Waterloo", (10 + 12 + 14) / 3 = 12

    cout << " test1 =  " << test1 << " test2 =  " << test2 << " test3 =  " << test3 << endl;
}