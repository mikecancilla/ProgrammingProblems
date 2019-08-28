/*
Given two arrays of strings a1 and a2 return a sorted array r in lexicographical order of the strings of a1 which are substrings of strings of a2.

#Example 1: a1 = ["arp", "live", "strong"]

a2 = ["lively", "alive", "harp", "sharp", "armstrong"]

returns ["arp", "live", "strong"]

#Example 2: a1 = ["tarp", "mice", "bull"]

a2 = ["lively", "alive", "harp", "sharp", "armstrong"]

returns []

Notes:
Arrays are written in "general" notation. See "Your Test Cases" for examples in your language.

In Shell bash a1 and a2 are strings. The return is a string where words are separated by commas.

Beware: r must be without duplicates.
Don't mutate the inputs.
*/

#include <vector>
#include <string>
#include <set>

std::vector<std::string> inArray(std::vector<std::string> &array1, std::vector<std::string> &array2)
{
    std::set<std::string> theSet;

    for(auto s1 : array1)
    {
        for(auto s2 : array2)
        {
            if(std::string::npos != s2.find(s1))
                theSet.insert(s1);
        }
    }

    std::vector<std::string> ret;
    for(auto s : theSet)
        ret.push_back(s);

    return ret;
}

void DoWhichAreIn()
{
    std::vector<std::string> s1 = {"arp", "live", "strong"};
    std::vector<std::string> s2 = {"lively", "alive", "harp", "sharp", "armstrong"};

    std::vector<std::string> ret = inArray(s1, s2);
}