/*
This problem was asked by Quora.

Given a string, find the palindrome that can be made by inserting the fewest number of characters as possible anywhere in the word. If there is more than one palindrome of minimum length that can be made, return the lexicographically earliest one (the first one alphabetically).

For example, given the string "race", you should return "ecarace", since we can add three letters to it (which is the smallest amount to make a palindrome). There are seven other palindromes that can be made from "race" by adding three letters, but "ecarace" comes first alphabetically.

As another example, given the string "google", you should return "elgoogle".
*/

/*
G O O G L E S
0 1 2 3 4 5

^         ^
|         |
L         R
*/

#include <string>

bool IsPalindrome(const std::string &s, int l, int r)
{
    int length = (r - l + 1) / 2;
    bool same = true;

    for(int i = 0; i < length; i++)
    {
        if(s[l] != s[r])
        {
            same = false;
            break;
        }
    }

    return same;
}

void DoPalindrome()
{
//    std::string s = "LABGBAR";
    std::string s = "RACE";
    bool foundPalindrome = false;

    int l = 0, r = 0;
    int endStart = s.length() - 1;
    int endLetter = s.length() / 2;

    while(l < endLetter && !foundPalindrome)
    {
        r = endStart;

        while(r >= endLetter && !foundPalindrome)
        {
            if(foundPalindrome = IsPalindrome(s, l, r))
            {
                foundPalindrome = true;
                break;
            }

            r--;
        }

        if(foundPalindrome)
            break;

        l++;
    }

    std::string palindrome;

    if(foundPalindrome)
    {
        if(l && r == endStart)
        {
            palindrome = s.substr(0, r-l+1);
            for(int i = l; i >= 0; i--)
                palindrome += s[i];
        }
        else if(l == 0 && r < endStart)
        {
            for(int i = endStart; i > r; i--)
                palindrome += s[i];

            palindrome += s;
        }
        else if(l && r < endStart)
        {
            palindrome = s;
            for(int i = endStart-1; i >= 0; i--)
                palindrome += s[i];
        }
    }
    else
    {
        palindrome = s;
        for(int i = endStart-1; i >= 0; i--)
            palindrome += s[i];
    }
}