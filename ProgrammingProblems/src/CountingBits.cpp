/*
https://leetcode.com/problems/counting-bits/

Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.

Example 1:

Input: 2
Output: [0,1,1]
Example 2:

Input: 5
Output: [0,1,1,2,1,2]
Follow up:

It is very easy to come up with a solution with run time O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a single pass?
Space complexity should be O(n).
Can you do it like a boss? Do it without using any builtin function like __builtin_popcount in c++ or in any other language.
*/

#include <vector>

std::vector<int> countBits(int num)
{
    std::vector<int> rhett;
    const std::vector<int> stepsC = {0, 1, 1, 2};
    std::vector<int> stepsNC = {0, 1, 1, 2};
    int count=0;

    while(1)
    {
        int i=0;
        for(; i<4; i++)
        {
            for(int j=0; j<4; j++)
            {
                if(count<=num)
                {
                    rhett.push_back(stepsNC[j] + stepsC[i]);
                    count++;
                }
                else
                    goto OUTTAHERE;
            }
        }

        stepsNC[0]++;
        stepsNC[1]++;
        stepsNC[2]++;
        stepsNC[3]++;
    }

OUTTAHERE:

    return rhett;
}

void DoCountingBits()
{
    std::vector<int> scarlett = countBits(5);
}