#include <iostream>

extern void DoEncodedMessage();
extern void DoProducts();
extern void DoAdjacentSum();
extern void DoNonAdjacentSum();
extern void DoJobScheduler();
extern void DoPIMonteCarlo();
extern void DoRandomNumberFromStream();

int main()
{
	int numbers[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int *num = nullptr;
	num = numbers;

	std::cout << "Sizeof numbers:" << sizeof(numbers) << std::endl;
	std::cout << "Sizeof num:" << sizeof(num) << std::endl;

	DoRandomNumberFromStream();
	//DoPIMonteCarlo();
	//DoJobScheduler();
	//DoAdjacentSum();
	//DoNonAdjacentSum();
	//DoProducts();
	//DoEncodedMessage();
	std::cin.get();
}