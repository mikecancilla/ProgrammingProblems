#include <iostream>
#include <vector>

void DoFactorialBigNumbers()
{
    int num = 171, cur, arr[200], temp = 0, pos = 1;
    arr[0] =1;
    for(int i=1; i<=num; i++) {
        for(int j=0; j<pos; j++) {
            cur = i * arr[j] + temp;
            arr[j] = cur % 10;
            temp = cur / 10;
        }
        while(temp > 0) {
            arr[pos++] = temp % 10;
            temp = temp/10;
        }
    }
    for(int i=pos-1; i>=0; i--)
        std::cout << arr[i];

    std::cout << '\n';
}

void DoMyBigFactorial1()
{
    unsigned int num=30, numLength=1, carry=0;
    std::vector<int> array;

    array.push_back(1);

    for(unsigned int i=1; i<num; i++)
    {
        for(unsigned int j=0; j<numLength; j++)
        {
            unsigned int result = i * array[j] + carry;
            array[j] = result % 10;
            carry = result / 10;
        }
        while(carry)
        {
            numLength++;
            array.push_back(carry % 10);
            carry /= 10;
        }
    }

    for(int i = array.size()-1; i>=0; i--)
        std::cout << array[i];
    std::cout << '\n';
}
