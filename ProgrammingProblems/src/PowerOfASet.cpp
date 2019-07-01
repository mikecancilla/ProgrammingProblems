/*
This problem was asked by Google.

The power set of a set is the set of all its subsets. Write a function that, given a set, generates its power set.

For example, given the set {1, 2, 3}, it should return {{}, {1}, {2}, {3}, {1, 2}, {1, 3}, {2, 3}, {1, 2, 3}}.

You may also use a list or array to represent a set.
*/

#include <vector>

std::vector<std::vector<int>*> GeneratePowerSet(std::vector<int> set)
{
    std::vector<std::vector<int>*> ret;

    ret.push_back(new std::vector<int>());
//    ret.push_back(new)

//    for(int i = 0; i < set.size(); i++)

    return ret;
}

void DoPowerSet()
{
    std::vector<int> set = { 1, 2, 3 };

    std::vector<std::vector<int>*> powerSet;

    powerSet = GeneratePowerSet(set);

    for(int i = 0; i < powerSet.size(); i++)
        delete powerSet[i];
}