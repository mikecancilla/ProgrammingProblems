/*
The area of a circle is defined as πr^2. Estimate π to 3 decimal places using a Monte Carlo method.

Hint: The basic equation of a circle is x2 + y2 = r2.

area of circle                 num point in circle
--------------  approximately  -------------------
area of square                      num points

Use square of sides 1.  Area = 1
Circle of r 1/2 = PI*(1/2)^2 = PI/4

PI/4 / 1 = PI/4

PI/4 approximately num point in circle / num points

PI = 4 * (in/total)
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

void DoPIMonteCarlo()
{
	unsigned int num_in_circle = 0;
	double x, y;

	srand(time(NULL));

	unsigned int num_times;

	for (;;)
	{
		std::cout << "How many times should I Monte Carlo? ";
		std::cin >> num_times;

		if (0 == num_times)
			break;

		num_in_circle = 0;

		for (unsigned int i = 0; i < num_times; i++)
		{
			x = (double)rand() / (double)RAND_MAX;
			x -= 0.5f;

			y = (double)rand() / (double)RAND_MAX;
			y -= 0.5f;

			if ((x*x) + (y*y) < 0.25f)
				num_in_circle++;
		}

		std::cout << "PI = " << 4.0 * ((double)num_in_circle / (double)num_times) << std::endl;
	}
}