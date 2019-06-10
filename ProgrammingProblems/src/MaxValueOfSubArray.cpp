/*
    This problem was asked by Google.

    Given an array of integers and a number k, where 1 <= k <= length of the array, compute the maximum values of each subarray of length k.

    For example, given array = [10, 5, 2, 7, 8, 7] and k = 3, we should get: [10, 7, 8, 8], since:

    10 = max(10, 5, 2)
    7 = max(5, 2, 7)
    8 = max(2, 7, 8)
    8 = max(7, 8, 7)
    Do this in O(n) time and O(k) space. You can modify the input array in-place and you do not need to store the results. You can simply print them out as you compute them.
*/

#include <iostream>
#include <deque>
#include <algorithm>

void FindAndPrintMaxValuesSTL(const int* array, const unsigned int length, const unsigned int windowSize)
{
    std::deque<int> values;

    for (unsigned int j = 0; j < windowSize; j++)
        values.push_back(array[j]);

    for(unsigned int i = 0; i + windowSize < length+1; i++)
    {
        std::deque<int>::iterator result = std::max_element(values.begin(), values.end());
        std::cout << *result << std::endl;

        values.pop_front();

        values.push_back(array[i+windowSize]);
    }
}

void FindAndPrintMaxValues(const int* array, const unsigned int length, const unsigned int windowSize)
{
    int max;

    for (unsigned int i = 0; i < length - windowSize + 1; i++)
    {
        max = array[i];

        for (unsigned int j = i+1; j < i+windowSize; j++)
        {
            if(array[j] > max)
                max = array[j];
        }

        std::cout << max << std::endl;
    }
}

void DoMaxValueSubArray()
{
    int array[] = {10, 5, 2, 7, 8, 7};

    FindAndPrintMaxValues(array, sizeof(array) / sizeof(int), 3);
    FindAndPrintMaxValuesSTL(array, sizeof(array)/sizeof(int), 3);
}