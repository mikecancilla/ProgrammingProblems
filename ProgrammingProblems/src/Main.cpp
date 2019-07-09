#include <iostream>

extern void DoEncodedMessage();
extern void DoProducts();
extern void DoAdjacentSum();
extern void DoNonAdjacentSum();
extern void DoJobScheduler();
extern void DoPIMonteCarlo();
extern void DoRandomNumberFromStream();
extern void DoMaxValueSubArray();
extern void DoLinkedListIntersection();
extern void DoClassroomTimes();
extern void DoStringFromDictionary();
extern void DoWallTilePath();
extern void DoBracketMatching();
extern void DoAutoComplete();
extern void DoTextJustification();
extern void DoRunLength();
extern void DoTrappedWater();
extern void DoEditDistance();
extern void DoPalindrome();
extern void DoRGBSort();
extern void DoPowerSet();
extern void DoFlightItinerary();
extern void DoStack();
//extern void DoLinkedListNoMalloc();
extern "C" void DoLinkedListNoMalloc_c();
extern void DoMaxValueSubArrayKadane();

int main()
{
/*
    int numbers[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int *num = nullptr;
	num = numbers;

	std::cout << "Sizeof numbers:" << sizeof(numbers) << std::endl;
	std::cout << "Sizeof num:" << sizeof(num) << std::endl;
*/

    DoMaxValueSubArrayKadane();
    //DoLinkedListNoMalloc_c();
    //DoLinkedListNoMalloc();
    //DoStack();
    //DoFlightItinerary();
    //DoPowerSet();
    //DoRGBSort();
    //DoPalindrome();
    //DoEditDistance();
    //DoTrappedWater();
    //DoRunLength();
    //DoTextJustification();
    //DoAutoComplete();
	//DoBracketMatching();
	//DoWallTilePath();
    //DoStringFromDictionary();
    //DoClassroomTimes();
    //DoLinkedListIntersection();
    //DoMaxValueSubArray();
	//DoRandomNumberFromStream();
	//DoPIMonteCarlo();
	//DoJobScheduler();
	//DoAdjacentSum();
	//DoNonAdjacentSum();
	//DoProducts();
	//DoEncodedMessage();
	std::cin.get();
}