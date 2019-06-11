/*
This problem was asked by Snapchat.

Given an array of time intervals(start, end) for classroom lectures(possibly overlapping), find the minimum number of rooms required.

For example, given[(30, 75), (0, 50), (60, 150)], you should return 2.
*/

#include <iostream>
#include <vector>
#include <utility>

struct StartEndTimes
{
    unsigned int start, end;
};

unsigned int HowManyRooms(const StartEndTimes *times, unsigned int size)
{
    std::vector<std::pair<int, int>> rooms;

    if(0 == size)
        return 0;

    if(1 == size)
        return 1;

    rooms.push_back(std::make_pair(times[0].start, times[0].end));

    for (unsigned int i = 1; i < size; i++)
    {
        std::vector<std::pair<int, int>>::iterator room = rooms.begin();
        unsigned int roomCount = rooms.size();

        bool conflict = true;
        int assignRoom = -1;

        for(unsigned int roomNumber = 0; roomNumber < roomCount; roomNumber++)
        {
            if (times[i].start < room->second &&
                times[i].end > room->first)
            {
                conflict = true;
            }
            else
            {
                conflict = false;
                assignRoom = roomNumber;
                break;
            }

            room++;
        }

        if(conflict)
            rooms.push_back(std::make_pair(times[i].start, times[i].end));
        else
        {
            rooms[assignRoom].first = times[i].start;
            rooms[assignRoom].second = times[i].end;
        }
    }

    return rooms.size();
}

void DoClassroomTimes()
{
    // Sorted by start times.
    StartEndTimes times[] = { 0, 50,
                              30, 75,
                              60, 150,
                              80, 120,
                              160, 190 };

    unsigned int rooms = HowManyRooms(times, sizeof(times)/sizeof(StartEndTimes));

    std::cout << rooms << std::endl;
}
