#include <algorithm>
#include <string>
#include <iostream>
#include <cctype>

void DoReverse()
{
    std::string s = "abc ** dedc! ba?";
    std::string filteredString;

    for(auto c : s)
        if(std::isalpha(c))
            filteredString += c;

    std::string filteredString2 = filteredString;
    std::reverse(filteredString2.begin(), filteredString2.end());

    if(filteredString2 == filteredString)
        std::cout << "Palindrome\n";
    else
        std::cout << "Not Palindrome\n";
}