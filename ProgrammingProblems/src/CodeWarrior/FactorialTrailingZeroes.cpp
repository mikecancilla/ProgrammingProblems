#include <cstdint>
#include <cmath>

// http://mathworld.wolfram.com/Factorial.html

/*
Find number of zeroes Z of n!

    Kmax
    ---
Z = \   floor(n/5^k)
    /
    ---
    K=1

where Kmax = floor(log5(n))

-- ALSO --

    logb a = logc a / logc b

Therefore:

    // function to evaluate logarithm a base-b
    uint32_t log(uint32_t a, uint32_t b)
    {
        return log2(a) / log2(b);
    }
*/

// Function to evaluate Binary logarithm
uint16_t log2(uint32_t n)
{
    uint16_t logValue = -1;
    while (n)
    {
        logValue++;
        n >>= 1;
    }
    
    return logValue;
}

// function to evaluate logarithm a base-b
uint32_t log(uint32_t a, uint32_t b)
{
    return log2(a) / log2(b);
}

void DoFactorialTrailingZeroes()
{
    unsigned int n = 10;
    unsigned int kMax = log(n, 5);
    unsigned int Z = 0;

    for(int k=1; k<=kMax; k++)
        Z += floor(n/pow(5.0, k));
}