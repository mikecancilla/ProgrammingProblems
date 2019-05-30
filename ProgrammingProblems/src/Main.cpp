#include <iostream>

extern void DoEncodedMessage();
extern void DoProducts();

int main()
{
	DoProducts();
	//DoEncodedMessage();
	std::cin.get();
}