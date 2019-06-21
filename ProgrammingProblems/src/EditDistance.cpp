/*
This problem was asked by Google.

The edit distance between two strings refers to the minimum number of character insertions, deletions, and substitutions required to change one string to the other. For example, the edit distance between “kitten” and “sitting” is three: substitute the “k” for “s”, substitute the “e” for “i”, and append a “g”.

Given two strings, compute the edit distance between them.
*/

/*
Take length of longer string and subtract length of shorter string, store this remainder.
For the length of the shorter string
    compare each char
    inc if different
*/

#include <string>

unsigned int ComputeEditDistance(std::string &s1, std::string &s2)
{
    unsigned int remainder = 0;
    unsigned int compareDistance = 0;

    if(s1.length() > s2.length())
    {
        remainder = s1.length() - s2.length();
        compareDistance = s2.length();
    }
    else
    {
        remainder = s2.length() - s1.length();
        compareDistance = s1.length();
    }

    unsigned int differences = 0;
    for(unsigned int i = 0; i < compareDistance; i++)
    {
        if(s1[i] != s2[i])
            differences++;
    }

    return differences + remainder;
}

void DoEditDistance()
{
    std::string s1 = "sitting";
    std::string s2 = "kitten";

    unsigned int ret = ComputeEditDistance(s1, s2);
}