/*
This problem was asked by Amazon.

Given a N by M matrix of numbers, print out the matrix in a clockwise spiral.

For example, given the following matrix:

[[1,  2,  3,  4,  5],
 [6,  7,  8,  9,  10],
 [11, 12, 13, 14, 15],
 [16, 17, 18, 19, 20]]
You should print out the following:

1
2
3
4
5
10
15
20
19
18
17
16
11
6
7
8
9
14
13
12
*/

/*
xInc=1, 0, -1, 0
yInc=0, 1, 0, -1

xL=0, xR=4
yT=0, yB=3

while count < number of elements
  for X from xR - xL
  {
    print
    X += xInc
    Y += yInc
    count++
  }
  xInc = xInc++ % 4;
  yInc = yInc++ % 4;
  yT++

  for Y from yB - yT
  {
      print
      X += xInc
      Y += yInc
      count++
  }
  xInc = xInc++ % 4;
  yInc = yInc++ % 4;
  xR--

  for X from xR - xL
  {
    print
    X += xInc
    Y += yInc
    count++
  }
  xInc = xInc++ % 4;
  yInc = yInc++ % 4;
  yB--

  for Y from yB - yT
  {
      print
      X += xInc
      Y += yInc
      count++
  }
  xInc = xInc++ % 4;
  yInc = yInc++ % 4;
  xL++
  */

#include <cstdio>

#define w 5
#define h 4

#define ABS(x) ((x) >= 0 ? (x) : -(x))

bool PrintX(int *array, int &counter, int xStart, int xStop, int xInc, int y, int numElements)
{
    int numTimes = ABS(xStop - xStart) + 1;
    int x = xStart;
    for(int i = 0; i < numTimes; i++)
    {
        printf("%d\n", array[(w*y)+x]);
        x += xInc;
        counter++;
    }

    return (counter >= numElements);
}

bool PrintY(int *array, int &counter, int yStart, int yStop, int yInc, int x, int numElements)
{
    int numTimes = ABS(yStop - yStart) + 1;
    int y = yStart;
    for(int i = 0; i < numTimes; i++)
    {
        printf("%d\n", array[(w*y)+x]);
        y += yInc;
        counter++;
    }

    return (counter >= numElements);
}

void DoCircularPrint()
{
    int array[w*h] = {1,  2,  3,  4,  5,
                      6,  7,  8,  9,  10,
                      11, 12, 13, 14, 15,
                      16, 17, 18, 19, 20};

    int xStart=0, xStop=w-1;
    int yStart=0, yStop=h-1;

    int numElements = w * h;
    int counter = 0;

    while(1)
    {
        if(PrintX(array, counter, xStart, xStop, 1, yStart, numElements))
            break;

        yStart++;

        if(PrintY(array, counter, yStart, yStop, 1, xStop, numElements))
            break;

        xStop--;

        if(PrintX(array, counter, xStop, xStart, -1, yStop, numElements))
            break;

        yStop--;

        if(PrintY(array, counter, yStop, yStart, -1, xStart, numElements))
            break;

        xStart++;
    }
}