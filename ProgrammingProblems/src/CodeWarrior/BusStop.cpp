#include <utility>
#include <vector>

unsigned int number(const std::vector<std::pair<int, int>>& busStops)
{
    unsigned int sum = 0;
    for(int i=0; i<busStops.size(); i++)
        sum += busStops[i].first - busStops[i].second;
    return sum;
}

void DoBusStops()
{
    std::vector<std::pair<int, int>> busStops = { std::make_pair(10, 0),
                                                  std::make_pair(3, 5),
                                                  std::make_pair(5, 8)
                                                };

    int n = number(busStops);
}