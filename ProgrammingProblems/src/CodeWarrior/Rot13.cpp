/*
ROT13 is a simple letter substitution cipher that replaces a letter with the letter 13 letters after it in the alphabet. ROT13 is an example of the Caesar cipher.

Create a function that takes a string and returns the string ciphered with Rot13. If there are numbers or special characters included in the string, they should be returned as they are. Only letters from the latin/english alphabet should be shifted, like in the original Rot13 "implementation".
*/

#include <string>

std::string rot13(std::string msg)
{
    std::string ret;

    for(auto i = msg.begin(); i != msg.end(); i++)
    {
        uint8_t c = *i;
        if(c >= 'a' &&
           c <= 'z')
        {
            c += 13;
            if(c > 'z')
                ret.push_back('a' + c - 'z' - 1);
            else
                ret.push_back(c);
        }
        else if(c >= 'A' &&
                c <= 'Z')
        {
            c += 13;
            if(c > 'Z')
                ret.push_back('A' + c - 'Z' - 1);
            else
                ret.push_back(c);
        }
        else
            ret.push_back(*i);
    }


    return ret;
}

void DoRot13()
{
    std::string s = rot13("test");
    s = rot13("Test");
    s = rot13("AbCd");
    s = rot13("16*()");
    s = rot13("A7b7C7d");

}