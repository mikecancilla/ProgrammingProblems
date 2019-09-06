/*
https://leetcode.com/problems/minimum-window-substring/
Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

Example:

Input: S = "ADOBECODEBANC", T = "ABC"
Output: "BANC"
Note:

If there is no such window in S that covers all characters in T, return the empty string "".
If there is such window, you are guaranteed that there will always be only one unique minimum window in S.
*/

#include <string>

std::string minWindow(std::string set, std::string subSet)
{
    int r0 = 0;
    int r1 = INT_MAX;

    // For each char in set as start
    for(int start=0; start<set.size(); start++)
    {
        std::string subSetTemp = subSet;
        int i0=-1;
        int i1=0;
        bool bFound=false;

        for(int s=start; s<set.size() && !bFound; s++)
        {
            std::string::size_type f = subSetTemp.find(set[s]);
            if(f != std::string::npos)
            {
                subSetTemp.erase(f,1);
                if(-1 == i0)
                {
                    i0 = s;
                    i1 = i0;
                }
                else
                    i1 = s;

                if(0 == subSetTemp.size())
                    bFound = true;
            }
        }

        if(bFound)
        {
            if(i1 - i0 < r1 - r0)
            {
                r0 = i0;
                r1 = i1;
            }
        }
    }

    if(r1 - r0 != INT_MAX)
    {
        std::string ret;
        for(int i=r0; i<=r1; i++)
            ret.push_back(set[i]);

        return ret;
    }

    return {};
}

void DoMinimumWindowSubString()
{
    std::string set = "ADOBECODEBANC";
    std::string subSet = "CBA";
//    std::string set = "A";
//    std::string subSet = "A";
    std::string ret = minWindow(set, subSet);
}