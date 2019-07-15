/*
This problem was asked by Microsoft.

Implement a URL shortener with the following methods:

shorten(url), which shortens the url into a six-character alphanumeric string, such as zLg6wl.
restore(short), which expands the shortened string into the original url. If no such shortened string exists, return null.
Hint: What if we enter the same URL twice?
*/

/*
SOLUTION

A Better Solution is to use the integer id stored in the database and convert the integer to a character string that is at most 6 characters long. This problem can basically seen as a base conversion problem where we have a 10 digit input number and we want to convert it into a 6 character long string.

Below is one important observation about possible characters in URL.

A URL character can be one of the following
1) A lower case alphabet [‘a’ to ‘z’], total 26 characters
2) An upper case alphabet [‘A’ to ‘Z’], total 26 characters
3) A digit [‘0’ to ‘9’], total 10 characters

There are total 26 + 26 + 10 = 62 possible characters.

So the task is to convert a decimal number to base 62 number.

To get the original long URL, we need to get URL id in the database. The id can be obtained using base 62 to decimal conversion.
*/

// C++ program to generate short url from integer id and 
// integer id back from short url. 
#include<iostream> 
#include<algorithm> 
#include<string>

// Function to generate a short url from integer ID 
std::string idToShortURL(long int n)
{ 
    // Map to store 62 possible characters 
    char map[] = "abcdefghijklmnopqrstuvwxyzABCDEF"
                 "GHIJKLMNOPQRSTUVWXYZ0123456789"; 
  
    std::string shorturl; 
  
    // Convert given integer id to a base 62 number 
    while (n) 
    { 
        // use above map to store actual character 
        // in short url 
        shorturl.push_back(map[n%62]); 
        n = n/62; 
    } 
  
    // Reverse shortURL to complete base conversion 
    std::reverse(shorturl.begin(), shorturl.end()); 
  
    return shorturl; 
} 
  
// Function to get integer ID back from a short url 
long int shortURLtoID(std::string shorturl) 
{ 
    long int id = 0; // initialize result 
  
    // A simple base conversion logic 
    for (int i=0; i < shorturl.length(); i++) 
    { 
        if ('a' <= shorturl[i] && shorturl[i] <= 'z') 
          id = id*62 + shorturl[i] - 'a'; 
        if ('A' <= shorturl[i] && shorturl[i] <= 'Z') 
          id = id*62 + shorturl[i] - 'A' + 26; 
        if ('0' <= shorturl[i] && shorturl[i] <= '9') 
          id = id*62 + shorturl[i] - '0' + 52; 
    } 
    return id; 
} 
  
// Driver program to test above function 
void DoShortURL() 
{ 
    int n = 12345; 
    std::string shorturl = idToShortURL(n); 
    std::cout << "Generated short url is " << shorturl << std::endl; 
    std::cout << "Id from url is " << shortURLtoID(shorturl); 
} 
