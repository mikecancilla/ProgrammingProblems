/*
This problem was asked by Microsoft.

Given a dictionary of words and a string made up of those words(no spaces), return the original sentence in a list.If there is more than one possible reconstruction, return any of them.
If there is no possible reconstruction, then return null.

For example, given the set of words 'quick', 'brown', 'the', 'fox', and the string "thequickbrownfox", you should return['the', 'quick', 'brown', 'fox'].

Given the set of words 'bed', 'bath', 'bedbath', 'and', 'beyond', and the string "bedbathandbeyond", return either['bed', 'bath', 'and', 'beyond] or ['bedbath', 'and', 'beyond'].
*/

#include <iostream>
#include <vector>
#include <string>

/*
std::vector<std::string> FindStrings(char *inputString, std::vector<std::string>& dictionary)
{
    std::vector<std::string> retVector;

    for (std::string word : dictionary)
    {
        if (char* ptr = std::strstr(inputString, word.c_str()))
        {
            retVector.push_back(word);

            for(unsigned int i = 0; i < word.length(); i++)
                ptr[i] = ' ';
        }
    }

    return retVector;
};
*/

std::vector<std::string> FindStrings(char* inputString, std::vector<std::string>& dictionary)
{
    std::vector<std::string> retVector;
    unsigned int stringLength = std::strlen(inputString);

    for (unsigned int i = 0; i < stringLength; i++)
    {
        bool found = false;
        for (unsigned int j = 0; j < dictionary.size() && !found; j++)
        {
            std::string word = dictionary[j];
            if (0 == std::strncmp(inputString + i, word.c_str(), word.length()))
            {
                retVector.push_back(word);
                i += word.length() - 1;
                found = true;
            }
        }
    }

    return retVector;
}

void DoStringFromDictionary()
{
    char inputString[64] = "thequickbrownfox";
    std::vector<std::string> dictionary = {"quick", "brown", "the", "fox"};
    std::vector<std::string> returnStrings;

    returnStrings = FindStrings(inputString, dictionary);
}