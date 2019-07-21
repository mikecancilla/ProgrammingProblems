/*
Implement integer exponentiation. That is, implement the pow(x, y) function, where x and y are integers and returns x^y.

Do this faster than the naive method of repeated multiplication.

For example, pow(2, 10) should return 1024.
*/


/*
  2^5 = 2^2 * 2^2 * 2

  Divide y by 2, reduces number of multiplies by 2
*/

#include <iostream>

int pow(int x, int y)
{
    if(y == 0)
        return 1;

    if(y == 1)
        return x;

    int looper = y >> 1;
    int squared = x * x;
    int accumulator = squared;

    for(int i = 1; i < looper; i++)
        accumulator *= squared;

    if(y % 2)
        accumulator *= x;

    return accumulator;
}

void DoPow()
{
    std::cout << "Pow(" << 3 << "," << 7 << ") = " << pow(3, 7) << std::endl;
    std::cout << "Pow(" << 5 << "," << 0 << ") = " << pow(5, 0) << std::endl;
    std::cout << "Pow(" << 8 << "," << 1 << ") = " << pow(8, 1) << std::endl;
    std::cout << "Pow(" << 7 << "," << 6 << ") = " << pow(7, 6) << std::endl;
}