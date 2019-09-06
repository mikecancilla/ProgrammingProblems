#include <string>
#include <algorithm>

/*
    https://leetcode.com/problems/defanging-an-ip-address/
    
    Given a valid (IPv4) IP address, return a defanged version of that IP address.

    A defanged IP address replaces every period "." with "[.]".
    

    Example 1:

    Input: address = "1.1.1.1"
    Output: "1[.]1[.]1[.]1"
    Example 2:

    Input: address = "255.100.50.0"
    Output: "255[.]100[.]50[.]0"
 

    Constraints:

    The given address is a valid IPv4 address.
*/

void DoDefangIP()
{
    std::string ip = "192.168.1.25";
    std::string ipDefanged;
    std::for_each(ip.begin(), ip.end(), [&ipDefanged](char c) {if(c == '.') ipDefanged += "[.]"; else ipDefanged += c;});
}