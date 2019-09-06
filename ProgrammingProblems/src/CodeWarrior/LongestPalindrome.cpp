/*
Longest Palindrome
Find the length of the longest substring in the given string s that is the same in reverse.

As an example, if the input was “I like racecars that go fast”, the substring (racecar) length would be 7.

If the length of the input string is 0, the return value must be 0.

Example:
"a" -> 1 
"aab" -> 2  
"abcde" -> 1
"zzbaabcd" -> 4
"" -> 0
*/

#include <string>
#include <algorithm>

bool IsPalindrome(std::string s, unsigned int start, unsigned int end)
{
    while(start < end)
    {
        if(s[start++] != s[end--])
            return false;
    }

    return true;
}

void DoFindPalindrome()
{
//    std::string s = "abzcrczba";
//    bool b = IsPalindrome(s, 0, s.size() -1);

    //std::string s = "zzsjruiqauf";
    //std::string s = "abaablkj12345432133d";
    std::string s = "zbaabzbaab";
    //std::string s = "aa";

    bool found = false;

    int start=0, end=0, length=0;
    for(;start<s.size()-1; start++)
    {
        for(end=s.size()-1; end>start && !found; end--)
            found = IsPalindrome(s, start, end);

        if(found)
        {
            length = std::max(length, (end+2) - start);
            //start = end + 2;
            found = false;
        }
    }

}