/*
https://leetcode.com/problems/valid-palindrome-ii/
Given a non-empty string s, you may delete at most one character. Judge whether you can make it a palindrome.

Example 1:
Input: "aba"
Output: True
Example 2:
Input: "abca"
Output: True
Explanation: You could delete the character 'c'.
Note:
The string will only contain lowercase characters a-z. The maximum length of the string is 50000.
*/

#include <string>

bool WalkString(std::string &s, unsigned int &l, unsigned int &r)
{
    bool b = true;

    while(l < r)
    {
        if(s[l] != s[r])
        {
            b = false;
            break;
        }
        else
        {
            l++;
            r--;
        }
    }

    return b;
}

void DoValidPalindrome()
{
    std::string s = "abrcghhzgcba";
    s = "aguokepatgbnvfqmgmlcupuufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymdjgpfdhooxfuupuculmgmqfvnbgtapekouga";

    unsigned int l = 0;
    unsigned int r = s.size()-1;
    unsigned int k = 0;

    bool p = true;

    if(!WalkString(s, l, r))
    {
        unsigned int lTemp = l+1;
        unsigned int rTemp = r;
        if(!WalkString(s, lTemp, rTemp))
        {
            lTemp = l;
            rTemp = r-1;
            if(!WalkString(s, lTemp, rTemp))
                p = false;
        }
    }

/*
    while(l < r)
    {
        if(s[l] != s[r])
        {
            if(++k > 1)
            {
                p = false;
                break;
            }
            else
            {
                if(s[l] == s[r-1])
                    r--;
                else if(s[l+1] == s[r])
                    l++;
                else
                {
                    p = false;
                    break;
                }
            }
        }
        else
        {
            l++;
            r--;
        }
    }
*/
}
