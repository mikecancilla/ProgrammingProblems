/*
This problem was asked by Amazon.

Given an array of numbers, find the maximum sum of any contiguous subarray of the array.

For example, given the array [34, -50, 42, 14, -5, 86], the maximum sum would be 137, since we would take elements 42, 14, -5, and 86.

Given the array [-5, -1, -8, -9], the maximum sum would be 0, since we would not take any elements.

Do this in O(N) time.
*/

/*
    Keep track of 4 variables:
       currentMax
       globalMax
       startIndex
       stopIndex

    return globalMax
*/

#include <iostream>

#define MAX(x, y) ((x) > (y) ? (x) : (y))

int DoKadane(int* array, unsigned int arraySize, int &startIndex, int &endIndex)
{
    if(arraySize)
    {
        int currentMax = array[0],
            globalMax = array[0];

        for(int i = 1; i < arraySize; i++)
        {
            currentMax = MAX(array[i], currentMax + array[i]);
            if(currentMax > globalMax)
                globalMax = currentMax;
        }

        return MAX(0, globalMax);
    }

    return 0;
}

void DoMaxValueSubArrayKadane()
{
//    int array[] = {34, -50, 42, 14, -5, 86};
    int array[] = {-5, -1, -8, -9};
    int startIndex = 0;
    int endIndex = 0;

    int max = DoKadane(array, sizeof(array) / sizeof(*array), startIndex, endIndex);
    std::cout << "The max is: " << max << std::endl;
}