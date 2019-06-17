/*
Implement an autocomplete system. That is, given a query string s and a set of all possible query strings, return all strings in the set that have s as a prefix.

For example, given the query string de and the set of strings [dog, deer, deal], return [deer, deal].

Hint: Try preprocessing the dictionary into a more efficient data structure to speed up queries.
*/

/*
Create an array of 26 vector<string>, one per letter of the alphabet
lower case only
Store each word in the dictionary in the vector that starts with the first letter of the word
*/

#include <vector>
#include <string>
#include <algorithm>

class Dictionary
{
	std::vector<std::string> dictionary[26];

public:
	void Insert(std::string s)
	{
		dictionary['z' - s[0]].push_back(s);
	}

	std::vector<std::string> Lookup(std::string queryString)
	{
		std::vector<std::string> ret;
		std::vector<std::string> v = dictionary['z' - queryString[0]];

		for(auto str : v)
		{
			if(0 == strncmp(queryString.c_str(), str.c_str(), queryString.length()))
				ret.push_back(str);
		}

		return ret;
	}
};

void DoAutoComplete()
{
	Dictionary d;

	d.Insert("apple");
	d.Insert("orange");
	d.Insert("olive");
	d.Insert("grapefruit");
	d.Insert("pear");
	d.Insert("peach");
	d.Insert("banana");

	std::vector<std::string> ret = d.Lookup("pea");
	ret = d.Lookup("fart");
	ret = d.Lookup("o");
}