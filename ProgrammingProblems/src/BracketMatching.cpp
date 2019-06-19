/*
This problem was asked by Facebook.

Given a string of round, curly, and square open and closing brackets, return whether the brackets are balanced (well-formed).

For example, given the string "([])[]({})", you should return true.

Given the string "([)]" or "((()", you should return false.
*/

/*
    Two pointers, rear and current
	For each open bracket rear points to that
	For each closing bracket
	    check if rear == current
		   rear--
		else 
		   false

	return true
*/

#include <iostream>
#include <string>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

bool BracketsWellFormed(std::string &brackets)
{
	int rear = 0;

	for(int cur = 0; cur < brackets.length(); cur++)
	{
		if(brackets[cur] == '{' ||
		   brackets[cur] == '(' ||
		   brackets[cur] == '[')
		{
   			rear = cur;
		}
		else if(brackets[cur] == '}')
		{
			if(brackets[rear] != '{')
				return false;

			rear = MAX(0, rear-1);
		}
		else if(brackets[cur] == ')')
		{
			if(brackets[rear] != '(')
				return false;

			rear = MAX(0, rear-1);
		}
		else if(brackets[cur] == ']')
		{
			if(brackets[rear] != '[')
				return false;

			rear = MAX(0, rear-1);
		}
	}

	return true;
}

void DoBracketMatching()
{
    std::string brackets = "{[])}";

	bool b = BracketsWellFormed(brackets);

	if(b)
		std::cout << "Brackets well formed" << std::endl;
	else
		std::cout << "Brackets not well formed" << std::endl;
}