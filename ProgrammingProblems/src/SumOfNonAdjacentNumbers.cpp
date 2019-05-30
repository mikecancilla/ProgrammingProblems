/*
This problem was asked by Airbnb.

Given a list of integers, write a function that returns the largest sum of non - adjacent numbers.Numbers can be 0 or negative.

For example, [2, 4, 6, 2, 5] should return 13, since we pick 2, 6, and 5.[5, 1, 1, 5] should return 10, since we pick 5 and 5.

Follow - up: Can you do this in O(N) time and constant space ?
*/

#include <vector>
#include <iostream>
#include <algorithm>

//static std::vector<int> g_Array = { 1, 2, 3, 4, 5 };
//static std::vector<int> g_Array = { -2, 3, 2, -1 };
//static std::vector<int> g_Array = { 5, 5, 10, 100, 10, 5 };
static std::vector<int> g_Array = { 5, 1, 1, 5 };

void DoNonAdjacentSum()
{
	int max = 0;

	if (g_Array.size())
	{
		int incl = g_Array[0];
		int excl = 0;
		int excl_new = 0;

		for (int i = 1; i < g_Array.size(); i++)
		{
			excl_new = (incl > excl) ? incl : excl;

			incl = excl + g_Array[i];
			excl = excl_new;
		}

		max = (incl > excl) ? incl : excl;
	}

	std::cout << "For vector { ";
	for (auto &element : g_Array)
		std::cout << element << " ";
	std::cout << "}" << std::endl;

	std::cout << "Max Non-Adjacent is: " << max << std::endl;
}

void DoAdjacentSum()
{
	int max_current, max_global;

	if (!g_Array.size())
		max_global = 0;
	else
	{
		max_current = max_global = g_Array[0];

		for (int i = 1; i < g_Array.size(); i++)
		{
			max_current = std::max(g_Array[i], max_current + g_Array[i]);
			if (max_current > max_global)
				max_global = max_current;
		}
	}

	std::cout << "For vector { ";
	for (auto &element : g_Array)
		std::cout << element << " ";
	std::cout << "}" << std::endl;

	std::cout << "Max Adjacent Sum is: " << max_global << std::endl;
}