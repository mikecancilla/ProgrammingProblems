/*
This problem was asked by Facebook.

Given a function that generates perfectly random numbers between 1 and k (inclusive), where k is an input, write a function that shuffles a deck of cards represented as an array using only swaps.

It should run in O(N) time.

Hint: Make sure each one of the 52! permutations of the deck is equally likely.
*/

// C++ Program to shuffle a given array
#include <iostream>
#include <time.h>

// A utility function to swap to integers
void swap (int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// A utility function to print an array
void PrintArray (int arr[], int n)
{
    for (int i = 0; i < n; i++)
        std::cout << arr[i] << " ";
    
    std::cout << std::endl;
}

// A function to generate a random
// permutation of arr[]
void ShuffleArray (int arr[], int n)
{
    // Use a different seed value so that
    // we don't get same result each time
    // we run this program
    srand (time(NULL));

    // Start from the last element and swap
    // one by one. We don't need to run for
    // the first element that's why i > 0
    for (int i = n - 1; i > 0; i--)
    {
        // Pick a random index from 0 to i
        int j = rand() % (i + 1);

        // Swap arr[i] with the element
        // at random index
        swap(&arr[i], &arr[j]);
    }
}

// Driver Code
void DoShuffleArray()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    ShuffleArray(arr, n);
    PrintArray(arr, n);
}