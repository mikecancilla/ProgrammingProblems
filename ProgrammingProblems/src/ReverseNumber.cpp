// Count the number of digits by / 10 over and over, increment counter
// Now you know what power of 10 to start at

#include <iostream>
#include <cmath>
#include <cstdint>

int reverse(int x)
{
    int ret = 0;
    int digit = 0;

    while(x != 0)
    {
        digit = x % 10;

        if(ret > INT_MAX/10 || (ret == INT_MAX/10 && digit > 7))
            return 0;

        if(ret < INT_MIN/10 || (ret == INT_MIN/10 && digit < -8))
            return 0;

        ret = (ret * 10) + digit;
        x /= 10;
    }

    return ret;
}

void DoReverseNumber()
{
    int rev = reverse(123);
    rev = reverse(-123);
    rev = reverse(2147483648);
    rev = reverse(1534236469);
    rev = reverse(1);
    rev = reverse(10);
    rev = reverse(102340);

    auto s = sizeof(int);

    //uint32_t x = pow(2, 31) - 1;
    //int b = 2147483646;
    //b++;
    //b++;

    int p = INT_MAX / 10;

    int a = pow(2,31);
    int c = -(int)(2147483648);
    //if(c == pow(2,31))
    int r = c & 0x7fffffff;
    if(0 == r)
        std::cout << "whoops\n";

    if(0 == (c & 0x7fffffff))
        std::cout << "whoops\n";

    //    int y = pow(2,31) + 5;
    int y = pow(2,31);
    //y *= -1;
    //y--;
    //if(y < -pow(2,31))
    //    std::cout << "whoops\n";

    uint32_t z = y;

    if(z > pow(2,31) - 1)
        std::cout << "whoops\n";

    rev = reverse(pow(2,31) + 5);
}