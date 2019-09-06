#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
#include <math.h>

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
extern void DoArithmeticExpressionBinaryTree();
extern void DoShuffleArray();
extern void DoLRUCache();
extern void DoShortURL();
extern void DoPow();
extern void DoCircularPrint();
extern "C" void DoLinkedListNoMalloc2_c();
extern void DoMaxTreeSum();
extern void DoBFSDFS();
extern void DoLongestConsecutiveElements();
extern void DoGoingToZero();
extern void DoFactorialBigNumbers();
extern void DoMyBigFactorial();
extern void DoCalculateSquareRoot();
extern void DoIsPrime();
extern void DoFindWord();
extern void DoTwoSum();
extern void DoReverseNumber();
extern void DoReverseBits();
extern void DoCountingBits();
extern void DoRomanNumerals();
extern void DoLongestCommonPrefix();
extern void DoContiguousSum();
extern void DoMinimumWindowSubString();
extern void DoGridTraversal();
extern void DoDefangIP();
extern void DoValidPalindrome();
extern void DoShiftAString();

// Take every 2nd char (evens) from the string, create a string out of them, S1
// Take every 2nd char (odds) from the string, create a string out of them, S2
// Conctat S1 after S2
// Do this n times
std::string encrypt(std::string text, int n)
{
    if(n && text.size())
    {
        for(int num = 0; num<n; num++)
        {
            std::string S1;

            for(int i = 0; i < text.size(); i+=2)
                S1 += text[i];

            std::string S2;

            for(int i = 1; i < text.size(); i+=2)
                S2 += text[i];

            text = S2 + S1;
        }
    }

    return text;
}

void DoSTLStuff()
{
    //extern void DoSetStuff();
    //DoSetStuff();

    extern void DoReverse();
    DoReverse();
}

void DoCodeWarsStuff()
{
    //extern void DoIsSquare();
    //DoIsSquare();

    //extern void DoEvaporator();
    //DoEvaporator();

    //extern void DoTribonacci();
    //DoTribonacci();

    //extern void DoBusStops();
    //DoBusStops();

    //extern void DoNumVowels();
    //DoNumVowels();

    //void DoDigitalRoot();
    //DoDigitalRoot();

    //void DoFindPalindrome();
    //DoFindPalindrome();

    //void DoWhichAreIn();
    //DoWhichAreIn();

    //void DoSnail();
    //DoSnail();

    //void DoRot13();
    //DoRot13();

    //void DoChange();
    //DoChange();

    //void DoFactorialTrailingZeroes();
    //DoFactorialTrailingZeroes();

    //void DoBallUpwards();
    //DoBallUpwards();

    void DoSuperMarketQueue();
    DoSuperMarketQueue();
}

int main()
{
    //DoSTLStuff();

    //DoCodeWarsStuff();

    //int n = 2;
    //std::vector<long> queues(n, 0);

    // Pointer to Lambda function

//    auto p = [](int x, int y) { std::cout << x << " " << y << std::endl; };
//    p(1, 2);

//    std::string s = "hitheremyfriend";
//    for(auto &x : s)
//        x = 'a'+(x-'a'+13)%26;

/*
    int numbers[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int *num = nullptr;
	num = numbers;

	std::cout << "Sizeof numbers:" << sizeof(numbers) << std::endl;
	std::cout << "Sizeof num:" << sizeof(num) << std::endl;
*/

//    std::vector<int> v = { 2, 3, 4, 5, 6, 7, 8 };
//    for(std::vector<int>::iterator i = v.begin(); i < v.end(); i++)
//        std::cout << *i << std::endl;

    //std::string s1("aretheyhere");
    //std::string s2("yestheyarehere");

//    std::string s = "This is a test!";
//    s = encrypt(s, 1);

    DoShiftAString();
    //DoValidPalindrome();
    //DoDefangIP();
    //DoGridTraversal();
    //DoMinimumWindowSubString();
    //DoContiguousSum();
    //DoLongestCommonPrefix();
    //DoRomanNumerals();
    //DoCountingBits();
    //DoReverseBits();
    //DoReverseNumber();
    //DoTwoSum();
    //DoFindWord();
    //DoIsPrime();
    //DoCalculateSquareRoot();
    //DoMyBigFactorial();
    //DoFactorialBigNumbers();
    //DoGoingToZero();
    //DoLongestConsecutiveElements();
    //DoBFSDFS();
    //DoMaxTreeSum();
    //DoLinkedListNoMalloc2_c();
    //DoCircularPrint();
    //DoPow();
    //DoShortURL();
    //DoLRUCache();
    //DoShuffleArray();
    //DoArithmeticExpressionBinaryTree();
    //DoMaxValueSubArrayKadane();
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