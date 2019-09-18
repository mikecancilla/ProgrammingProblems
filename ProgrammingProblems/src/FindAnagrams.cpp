/*
Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.

Example 1:

Input:
s: "cbaebabacd" p: "abc"

Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input:
s: "abab" p: "ab"

Output:
[0, 1, 2]

Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
*/

#include <string>
#include <iostream>
#include <vector>

#define MAX 256 // Number of 8 bit ASCII characters

bool countEqual(unsigned int *patCount, unsigned int *textCount)
{
    for(unsigned int i=0; i<MAX; i++)
    {
        if(patCount[i] != textCount[i])
            return false;
    }

    return true;
}

std::vector<unsigned int> findAnagrams(std::string text, std::string pat)
{
    std::vector <unsigned int> v;
    unsigned int patLen = pat.size();
    unsigned int textLen = text.size();

    unsigned int patCount[MAX] = {0};
    unsigned int textCount[MAX] = {0};

    unsigned int i = 0;
    for(; i<patLen; i++)
    {
        patCount[pat[i]]++;
        textCount[text[i]]++;
    }

    unsigned int j=0;
    for(; i<textLen; i++)
    {
        if(countEqual(patCount, textCount))
            v.push_back(j);

        textCount[text[j]]--;
        j++;
        textCount[text[i]]++;
    }

    if(countEqual(patCount, textCount))
        v.push_back(j);

    return v;
}

void DoFindAnagrams()
{
    std::string text = "cbaebabacd";
    std::string pat = "abc";

    text = "abab";
    pat = "ab";

    std::vector<unsigned int> v = findAnagrams(text, pat);
}