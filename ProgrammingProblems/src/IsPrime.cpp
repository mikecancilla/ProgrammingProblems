bool isPrime(int number) {
    if (number < 2)
        return false;

    if (number == 2)
        return true;
    else if (number % 2 == 0)
        return false;

    int i = 3;
    for (; i*i<=number; i=i+2)
    {
        if (number % i == 0) {
            return false;
        }
    }

    return true;
}

void DoIsPrime()
{
    bool b = isPrime(23);
}