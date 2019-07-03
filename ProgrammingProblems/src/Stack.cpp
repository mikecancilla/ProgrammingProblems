/*
This problem was asked by Amazon.

Implement a stack that has the following methods:

push(val), which pushes an element onto the stack
pop(), which pops off and returns the topmost element of the stack. If there are no elements in the stack, then it should throw an error or return null.
max(), which returns the maximum value in the stack currently. If there are no elements in the stack, then it should throw an error or return null.
Each method should run in constant time.
*/

#include <cstdlib>
#include <iostream>

#define OK 0
#define ERROR -1

class Stack
{
private:

    unsigned int numElements;
    int *stack;

public:

    Stack()
        : stack(nullptr)
        , numElements(0)
    {
    }

    void push(int i)
    {
        stack = (int *) realloc(stack, (numElements + 1) * sizeof(int));
        stack[numElements++] = i;
    }

    int pop(int *i)
    {
        if(numElements && i != nullptr)
        {
            *i = stack[numElements-1];
            numElements--;
            stack = (int *) realloc(stack, numElements * sizeof(int));

            return OK;
        }

        return ERROR;
    }

    int max(int *i)
    {
        if(numElements && i != nullptr)
        {
            int max = stack[0];
            for(int n = 1; n < numElements; n++)
            {
                if(stack[n] > max)
                    max = stack[n];
            }

            *i = max;

            return OK;
        }

        return ERROR;
    }

    int operator[](unsigned int i)
    {
        if(i < numElements)
            return stack[i];

        return ERROR;
    }

    unsigned int size()
    {
        return numElements;
    }
};

void DoStack()
{
    Stack s;

    s.push(1);
    s.push(3);
    s.push(5);
    s.push(4);

    int max;
    if(OK == s.max(&max))
        std::cout << "Stack max is: " << max << std::endl;

    std::cout << "Here is the stack:" << std::endl;

    int i;
    for(;;)
    {
        if(OK == s.pop(&i))
            std::cout << i << std::endl;
        else
            break;
    }
}