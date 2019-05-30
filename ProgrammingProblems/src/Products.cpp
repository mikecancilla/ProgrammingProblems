/*
This problem was asked by Uber.

Given an array of integers, return a new array such that each element at index i of the new array is the product of all the numbers in the original array except the one at i.

For example, if our input was [1, 2, 3, 4, 5], the expected output would be [120, 60, 40, 30, 24]. If our input was [3, 2, 1], the expected output would be [2, 3, 6].

Follow-up: what if you can't use division?
*/

#include <iostream>
#include <vector>

std::vector<int> g_Array = { 1, 2, 3, 4, 5 };

int GetProduct(const std::vector<int>::iterator& start, const std::vector<int>::iterator& end)
{
	int product = 1;

	for (std::vector<int>::iterator i = start; i != end; i++)
		product *= *i;

	return product;
}

void DoProducts()
{
	std::vector<int> out_vec;

	for (int i = 0; i < g_Array.size(); i++)
	{
		if (i == 0)
			out_vec.push_back(GetProduct(g_Array.begin() + 1, g_Array.end()));
		else if (i == g_Array.size() - 1)
			out_vec.push_back(GetProduct(g_Array.begin(), g_Array.end() - 1));
		else
		    out_vec.push_back(GetProduct(g_Array.begin(), g_Array.begin() + i) * GetProduct(g_Array.begin() + i + 1, g_Array.end()));
	}

	std::cout << "For vector { ";
	for (auto item : g_Array)
		std::cout << item << " ";
	std::cout << "}" << std::endl;

	std::cout << "Products are { ";
	for(auto item : out_vec)
		std::cout << item << " ";
	std::cout << "}" << std::endl;
}
