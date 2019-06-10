/*
    Given two singly linked lists that intersect at some point, find the intersecting node. The lists are non-cyclical.

    For example, given A = 3 -> 7 -> 8 -> 10 and B = 99 -> 1 -> 8 -> 10, return the node with value 8.

    In this example, assume nodes with the same value are the exact same node objects.

    Do this in O(M + N) time (where M and N are the lengths of the lists) and constant space.
*/

#include <iostream>
#include <vector>

void FindIntersection(const std::vector<int> &list1, const std::vector<int> &list2)
{
    for (auto i1 : list1)
    {
        for(auto i2 : list2)
            if(i1 == i2)
            {
                std::cout << "Intersection found at: " << i1 << std::endl;
                return;
            }

        std::cout << "No intersection found for: " << i1 << std::endl;
    }
}

void DoLinkedListIntersection()
{
    std::vector<int> list1 = { 10, 4, 1, 9, 12, 3, 5 };
    std::vector<int> list2 = { 22, 13, 7, 3, 6 };

    FindIntersection(list1, list2);
}