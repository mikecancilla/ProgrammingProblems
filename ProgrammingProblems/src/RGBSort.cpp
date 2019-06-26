/*
his problem was asked by Google.

Given an array of strictly the characters 'R', 'G', and 'B', segregate the values of the array so that all the Rs come first, the Gs come second, and the Bs come last. You can only swap elements of the array.

Do this in linear time and in-place.

For example, given the array ['G', 'B', 'R', 'R', 'B', 'R', 'G'], it should become ['R', 'R', 'R', 'G', 'G', 'B', 'B'].
*/

/*
- Insert R always at beginning.
- Insert G always after last R or before first B
- Insert B always always at end
*/

// Actual answer is here: https://www.geeksforgeeks.org/sort-an-array-of-0s-1s-and-2s/

#include <string>

void InsertR(std::string &s, int start, int end)
{
}

void InsertG(std::string &s, int start, int end)
{
}

void InsertB(std::string &s, int start, int end)
{
}

void Swap(std::string &s, int a, int b)
{
    char temp = s[b];
    s[b] = s[a];
    s[a] = temp;

}

void SwapToBeginning(std::string &s, int index)
{
    for(; index > 0; index--)
        Swap(s, index-1, index);
}

void SwapToEnd(std::string &s, int index)
{
    for(; index < s.length()-1; index++)
        Swap(s, index+1, index);
}

void DoRGBSort()
{
    std::string s = {'B', 'G', 'R', 'R', 'B', 'R', 'G'};
//    std::string s = {'B', 'G', 'R'};
//    std::string s = {'B', 'G', 'R', 'G'};

    for(int i = 0; i < s.length(); i++)
    {
        if('R' == s[i])
            SwapToBeginning(s, i);
        else if('B' == s[i])
            SwapToEnd(s, i);
    }
}