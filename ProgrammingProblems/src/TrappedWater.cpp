/*
This problem was asked by Facebook.

You are given an array of non-negative integers that represents an elevation map where each element is unit-width wall and the integer is the height. Suppose it will rain and all spots between two walls get filled up.

Compute how many units of water remain trapped on the map in O(N) time and O(1) space.

For example, given the input [2, 1, 2], we can hold 1 unit of water in the middle.

Given the input [3, 0, 1, 3, 0, 5], we can hold 3 units in the first index, 2 in the second, and 3 in the fourth index (we cannot hold 5 since it would run off to the left), so we can trap 8 units of water.
*/

/*
- Have a variables max, walker, total, cur_set
- Set max to first number[walker]
- Walk to right
- For each number[walker] < max, push number[walker] into cur_set
- If number[walker] >= max
    total += sum(cur_set)
    max = number[walker]
    cur_set = empty set
*/

#include <iostream>
#include <vector>

unsigned int FindTrappedWater(const std::vector<unsigned int> &numbers)
{
    unsigned int max = 0, total = 0, walker = 0;
    std::vector<unsigned int> cur_set;

    if(!numbers.size())
        return 0;

    max = numbers[walker];

    for(walker = 1; walker < numbers.size(); walker++)
    {
        if(numbers[walker] < max)
        {
            cur_set.push_back(max - numbers[walker]);
        }
        else if(numbers[walker] >= max)
        {
            unsigned int sum = 0;
            for(auto value : cur_set)
                sum += value;

            total += sum;
            max = numbers[walker];
            cur_set.clear();
        }
    }

    return total;
}

void DoTrappedWater()
{
//    const std::vector<unsigned int> numbers = {3, 0, 1, 3, 0, 5};
//    const std::vector<unsigned int> numbers = {2, 1, 2};
//    const std::vector<unsigned int> numbers = {3, 0, 1, 3, 0, 5, 4, 3, 2, 1};
    const std::vector<unsigned int> numbers = {3, 3, 3};

    unsigned int trappedWater = FindTrappedWater(numbers);
}