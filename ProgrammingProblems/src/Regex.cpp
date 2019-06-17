/*
This problem was asked by Facebook.

Implement regular expression matching with the following special characters:

. (period) which matches any single character
* (asterisk) which matches zero or more of the preceding element
That is, implement a function that takes in a string and a valid regular expression and returns whether or not the string matches the regular expression.

For example, given the regular expression "ra." and the string "ray", your function should return true. The same regular expression on the string "raymond" should return false.

Given the regular expression ".*at" and the string "chat", your function should return true. The same regular expression on the string "chats" should return false.
*/

/*
Rules

PreceedingChar = NULL;

ProcessDot
.
    PreceedingChar = cur inputChar
	move to next char

ProcessStar
*
    if(NULL == PreceedingChar)
		StopChar = NextInputChar  // special case for next char == .?
	    eat until StopChar
	else
		eat until not PreceedingChar

	PreceedingChar = cur input char

ProcessRegularChar
'a'
    compare cur regexChar to cur inputChar
	if cur regexChar == cur inputChar
		PreceedingChar = inputChar
		move to next char
	else
	    return false;



- Each of these returns the number of the char it stops on in inputString
int EatUntil(inputString, char, length)
int EatUntilNot(inputString, char, length)

- PreceedingChar = NULL
- Point to first char of input string, set counter to 0
- Take strlen of input string, set to length
- for each char of regex string, and inputCounter < length
    - Read one regexChar of regex string, inc regexCounter
	- If char != * or .
		compare cur regexChar to cur inputChar
		if cur regexChar == cur inputChar
			PreceedingChar = inputChar
			move to next char
		else
			return false;

	- If regexChar == .
        PreceedingChar = cur inputChar
	    move to next char

	- if regexChar == *
		if(NULL == PreceedingChar)
			StopChar = NextInputChar  // special case for next char == .?
			EatUntil(StopChar)
		else
			EatUntilNot(PreceedingChar)

		PreceedingChar = cur input char

- if inputCounter == length return true
- return false
*/