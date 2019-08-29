/*
    Example: Calculate the square root of 10 () to 2 decimal places.

    1. Find the two perfect square numbers it lies between.

    Solution:
    3^2 = 9 and 4^2 = 16, so  lies between 3 and 4.

    2. Divide 10 by 3. 10/3 = 3.33 (you can round off your answer)

    3. Average 3.33 and 3. (3.33 + 3)/2 = 3.1667

    Repeat step 2: 10/3.1667 = 3.1579
    Repeat step 3: Average 3.1579 and 3.1667. (3.1579 + 3.1667)/2 = 3.1623

    Try the answer --> Is 3.1623 squared equal to 10? 3.1623 x 3.1623 = 10.0001

    If this is accurate enough for you, you can stop! Otherwise, you can repeat steps 2 and 3.
*/

void DoCalculateSquareRoot()
{
    double n = 10;
    int i = 0;

    // 1. Find the two perfect square numbers it lies between.
    for(; i<1000000; i++)
        if(i*i < n && (i+1) * (i+1) > 10)
            break;

    // 2. Divide n by lower number. 10/3 = 3.33 (you can round off your answer)
    double d = n / i;

    // 3. Average d (3.33) and 3. (3.33 + 3)/2 = 3.1667
    double average = (d+i) / 2.f;

    // Repeat step 2: 10/3.1667 = 3.1579
    double d1 = n/average;

    // Repeat step 3: Average 3.1579 and 3.1667. (3.1579 + 3.1667)/2 = 3.1623
    average = (d1+average) / 2.f;

    // DONE!
    double square = average * average;
}
