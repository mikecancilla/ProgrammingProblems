/*
    Add stuff to a singly linked list.  Can't use malloc.

    I'm assuming you are trying to steer people toward not using the heap, but the stack only.

    I can only think of a statically allocated array of size n, or using stack memory with recursion.  You didn't specify removing items from the list.

    Approaches:
      1. Just a static array of size n.  No malloc.  TOO EASY
      2. Recusive stack hell.  (Shown below)

    Since pHead is global, you could multi thread this.  One thread to add items, another thread to walk the list.  Need to make access thread safe though.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    int value;
    struct Node *next;
};

static struct Node *pHead = NULL;
static struct Node *pTail = NULL;
static int bUnwinding = 0;

#define INPUT_MAX_LENGTH  20

// Call this to add items to a linked list.
// It will call itself recursively and append new items,
// or exit if the user hits <enter>
void AddToLinkedList()
{
    // Numbers get entered as a string, converted to int with atoi()
    char pInput[INPUT_MAX_LENGTH];
    
    // This is the linked list node for this iteration of the call stack
    struct Node n;

    // If the user enters a number, add it to the end of the linked list,
    // and recursively call AddToLinkedList()
    printf("Enter a number, or hit <enter> to stop: ");

    // Do not execute this while loop if we are unwinding the call stack
    while(!bUnwinding)
    {
        fgets(pInput, INPUT_MAX_LENGTH, stdin);

        if(pInput[0] == '\n')
            break;

        n.value = atoi(pInput);
        n.next = NULL;

        // If this is the first entry into the list, set head and tail
        if(NULL == pHead)
        {
            pHead = &n;
            pTail = &n;
        }
        else
        {
            pTail->next = &n;
            pTail = &n;
        }

        // Recurse to allow addition to the end of the linked list
        AddToLinkedList();
    }
 
    // If we get here, the user hit <enter>
    // Only access the linked list the first time,
    // not while unwinding the call stack.
    if(!bUnwinding)
    {
        printf("Here is the linked list you created: ");

        struct Node *p = pHead;
        while(p)
        {
            if(p->next)
                printf("%d, ", p->value);
            else
                printf("%d\n", p->value);

            p = p->next;
        }

        printf("Hit return to exit.");
        fgets(pInput, INPUT_MAX_LENGTH, stdin);
    }

    // We will now unwind the call stack
    bUnwinding = 1;
}

void DoLinkedListNoMalloc_c()
{
    AddToLinkedList();
}