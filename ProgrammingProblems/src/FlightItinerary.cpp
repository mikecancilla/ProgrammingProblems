/*
This problem was asked by Facebook.

Given an unordered list of flights taken by someone, each represented as (origin, destination) pairs, and a starting airport, compute the person's itinerary. If no such itinerary exists, return null. If there are multiple possible itineraries, return the lexicographically smallest one. All flights must be used in the itinerary.

For example, given the list of flights [('SFO', 'HKO'), ('YYZ', 'SFO'), ('YUL', 'YYZ'), ('HKO', 'ORD')] and starting airport 'YUL', you should return the list ['YUL', 'YYZ', 'SFO', 'HKO', 'ORD'].

Given the list of flights [('SFO', 'COM'), ('COM', 'YYZ')] and starting airport 'COM', you should return null.

Given the list of flights [('A', 'B'), ('A', 'C'), ('B', 'C'), ('C', 'A')] and starting airport 'A', you should return the list ['A', 'B', 'C', 'A', 'C'] even though ['A', 'C', 'A', 'B', 'C'] is also a valid itinerary. However, the first one is lexicographically smaller.
*/

/*
Given
- list of airport pairs
- start airport

0. if list of airports empty, return done
1. build a list of starting airports
    - if empty return done
2. choose the one lexigraphically least
3. add starting airport to set
4. make end airport start airport
5. go to 0
*/

#include <utility>
#include <vector>
#include <string>
#include <iostream>

typedef std::pair<std::string, std::string> Flight;
typedef std::vector<Flight> Itinerary;

void BuildIitinerary(const std::string start, Itinerary itinerary, std::vector<std::string> &retItinerary)
{
    if(!itinerary.size())
    {
        if("" != start)
            retItinerary.push_back(start);

        return;
    }

    Itinerary::iterator deleteMe;
    Flight start_flight;

    for(Itinerary::iterator i = itinerary.begin(); i < itinerary.end(); i++)
    {
        if(i->first == start)
        {
            if("" == start_flight.first)
            {
                start_flight = *i;
                deleteMe = i;
            }
            else
            {
                if((i->first + i->second) < (start_flight.first + start_flight.second))
                {
                    start_flight = *i;
                    deleteMe = i;
                }
            }
        }
    }

    if(start_flight.first == "")
        return;

    retItinerary.push_back(start_flight.first);
    itinerary.erase(deleteMe);

    BuildIitinerary(start_flight.second, itinerary, retItinerary);
}

void DoFlightItinerary()
{
    Itinerary itinerary;
    std::vector<std::string> retItinerary;

    // [('SFO', 'HKO'), ('YYZ', 'SFO'), ('YUL', 'YYZ'), ('HKO', 'ORD')]
    /*
    itinerary.push_back(std::make_pair("SFO", "HKO"));
    itinerary.push_back(std::make_pair("YYZ", "SFO"));
    itinerary.push_back(std::make_pair("YUL", "YYZ"));
    itinerary.push_back(std::make_pair("HKO", "ORD"));

    BuildIitinerary("YUL", itinerary, retItinerary);
    */

    // [('A', 'B'), ('A', 'C'), ('B', 'C'), ('C', 'A')]
    /*
    itinerary.push_back(std::make_pair("A", "B"));
    itinerary.push_back(std::make_pair("A", "C"));
    itinerary.push_back(std::make_pair("B", "C"));
    itinerary.push_back(std::make_pair("C", "A"));

    BuildIitinerary("A", itinerary, retItinerary);
    */

    // [('SFO', 'COM'), ('COM', 'YYZ')]
    itinerary.push_back(std::make_pair("SFO", "COM"));
    itinerary.push_back(std::make_pair("COM", "YYZ"));

    BuildIitinerary("COM", itinerary, retItinerary);

    if(itinerary.size() + 1 != retItinerary.size())
        std::cout << "No flights possible" << std::endl;
    else
    {
        std::cout << "Your fligts are: ";

        std::cout << retItinerary[0];

        for(std::vector<std::string>::iterator i = retItinerary.begin()+1; i < retItinerary.end(); i++)
            std::cout << ", " << *i;
    }
}