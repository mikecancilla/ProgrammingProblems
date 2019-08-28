#include <cstdlib>

bool is_square(int n)
{
    if(n < 0)
        return false;

    unsigned int i = 0;

    for(;;)
    {
        unsigned int product = i * i;

        if(product == n)
            return true;

        if(product > n)
            return false;

        i++;
    }

    return false;
}

void DoIsSquare()
{
    bool b = is_square(-1);
    b = is_square(0);
    b = is_square(3);
    b = is_square(4);
    b = is_square(25);
    b = is_square(26);
}