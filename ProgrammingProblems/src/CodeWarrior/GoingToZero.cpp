/*
    Consider the following numbers (where n! is factorial(n)):

    u1 = (1 / 1!) * (1!)
    u2 = (1 / 2!) * (1! + 2!)
    u3 = (1 / 3!) * (1! + 2! + 3!)
    un = (1 / n!) * (1! + 2! + 3! + ... + n!)
    Which will win: 1 / n! or (1! + 2! + 3! + ... + n!)?

    Are these numbers going to 0 because of 1/n! or to infinity due to the sum of factorials or to another number?

    Task
    Calculate (1 / n!) * (1! + 2! + 3! + ... + n!) for a given n, where n is an integer greater or equal to 1.

    To avoid discussions about rounding, return the result truncated to 6 decimal places, for example:

    1.0000989217538616 will be truncated to 1.000098
    1.2125000000000001 will be truncated to 1.2125
    Remark
    Keep in mind that factorials grow rather rapidly, and you need to handle large inputs.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <cmath>
#include <cstdio>
#include <cstdlib>

unsigned long long factorial(int n)
{
    unsigned long long fact = 1;

    while(n)
        fact *= n--;

    return fact;
}

double going(int n)
{
    //auto factorial = [](int n) {long double f=1; while(n) f *= n--; return f;};
    long long fact = factorial(n);
    long long result = fact;

    while(--n)
        result += factorial(n);

    result *= (1.f / fact);

    //char number[512];
    //sprintf(number, "%.6f", result);
    //return atof(number);

    size_t number = result * 1000000.f;
    result = number;
    return result / 1000000.f;
}

void DoGoingToZero()
{
    unsigned long long d = factorial(170);

    double r = 0;
    for(int i=170; i<300; i++)
        r = going(i);
}