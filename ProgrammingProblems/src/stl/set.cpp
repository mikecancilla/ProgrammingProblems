#include <set>
#include <iostream>

void DoSetStuff()
{
    std::set<int> s = {30, -5, 10, 22, 30, 30};

    for(auto i = s.begin(); i!=s.end(); i++)
        std::cout << *i << std::endl;
}