#include <cstdint>

uint32_t reverseBits(uint32_t n)
{
    uint32_t rhett=0;

    for(int i=0; i<32; i++)
    {
        rhett <<= 1;
        rhett |= n & 0x01;
        n >>= 1;
    }

    return rhett;
}

void DoReverseBits()
{
    uint32_t i = 0x06;

    reverseBits(i);
}