#include <iostream>

extern void DoEncodedMessage();
extern void DoProducts();
extern void DoAdjacentSum();
extern void DoNonAdjacentSum();
extern void DoJobScheduler();
extern void DoPIMonteCarlo();

int main()
{
	DoPIMonteCarlo();
	//DoJobScheduler();
	//DoAdjacentSum();
	//DoNonAdjacentSum();
	//DoProducts();
	//DoEncodedMessage();
	std::cin.get();
}