/*
This problem was asked by Amazon.

Run-length encoding is a fast and simple method of encoding strings. The basic idea is to represent repeated successive characters as a single count and character. For example, the string "AAAABBBCCDAA" would be encoded as "4A3B2C1D2A".

Implement run-length encoding and decoding. You can assume the string to be encoded have no digits and consists solely of alphabetic characters. You can assume the string to be decoded is valid.
*/

/*
Encode
    Read cur char
    count = 1
    while next char == cur char
        count++

    output count and cur char

#include <string>
*/

#include <iostream>
#include <string>
#include <cstdlib>

std::string Encode(std::string &s)
{
    std::string ret;
    int curPos = 0;

    while(curPos < s.length())
    {
        char curChar = s[curPos++];
        int size = 1;

        while(curPos < s.length() && s[curPos] == curChar)
        {
            curPos++;
            size++;
        }

        ret += std::to_string(size);
        ret += curChar;
    }

    return ret;
}

std::string Decode(std::string &s)
{
    std::string ret;
    int curPos = 0;

    while(curPos < s.length())
    {
        std::string number;

        while(curPos < s.length() && s[curPos] >= '0' && s[curPos] <= '9')
            number += s[curPos++];

        int count = std::atoi(number.c_str());
        for(int i = 0; i < count; i++)
            ret += s[curPos];

        curPos++;
    }

    return ret;
}

void DoRunLength()
{
    std::string encodeString = "AAAABBBBBBBBBBBBCCDAA";
    std::cout << "Encode of: " << encodeString << " is " << Encode(encodeString) << std::endl;

    std::string decodeString = "4A12B2C1D2A";
    std::cout << "Decode of: " << decodeString << " is " << Decode(decodeString) << std::endl;
}