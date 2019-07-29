//
// Dearest Adam:
//
// This is targeted at what you asked for: inserting into a linked list.
//
//   - Assuming singly linked list, so insertion is O(n)
//   - Nothing is done for removal, which would require deeper memory pool logic
//
// Go ahead and change MAX_MEMORY_POOL_NODES to test the boundaries
//


/*
Without using malloc or free, and using as little stack space as possible, write a standard C function to insert an unsigned long into a linked list ordered from smallest to largest.

You may include stddef.h and stdio.h but do not use any other libraries.

You may take as much time as you like, but you can expect a full implementation to take you about half an hour.

... So doing stuff on the stack kinda violates the 'as little stack space as possible'

Basically what I look for is if the person knows how pointers work and knows well enough to handle corner cases and check for errors.

To date, two people have written O(1) node allocators.

About a 10% of people do something crazy like assume that they can pull memory out of thin air without allocating it from anywhere.
*/

#include <stdio.h>

#define MAX_MEMORY_POOL_NODES 15

struct Node
{
    unsigned long value;
    struct Node *pNext;
};

static unsigned char g_memoryPool[MAX_MEMORY_POOL_NODES * sizeof(struct Node)];
static unsigned int g_numMemoryPoolNodes = 0;

struct Node *NodeMalloc()
{
    if(MAX_MEMORY_POOL_NODES == g_numMemoryPoolNodes)
        return NULL;

    return (struct Node*) (g_memoryPool + (g_numMemoryPoolNodes++ * sizeof(struct Node)));
}

// Returns 0 on error, 1 on success
unsigned int LinkedListInsert(struct Node **pHead, const unsigned long v)
{
    struct Node *pNode = NodeMalloc();

    // Too many kids in the pool?
    if(NULL == pNode)
        return 0;

    pNode->value = v;

    if(NULL == *pHead || v <= (*pHead)->value)
    {
        // Insert at beginning
        pNode->pNext = *pHead;
        *pHead = pNode;
    }
    else
    {
        // Insert to middle or end
        struct Node *pListWalker =*pHead;

        while(pListWalker->pNext && v > pListWalker->pNext->value)
            pListWalker = pListWalker->pNext;

        pNode->pNext = pListWalker->pNext;
        pListWalker->pNext = pNode;
    }

    return 1;
}

void DoLinkedListNoMalloc2_c()
{
    unsigned long numberSet[] = {8, 5, 7, 99, 55, 1, 123, 44, 43, 42};

    unsigned int numberSetSize = sizeof(numberSet) / sizeof(numberSet[0]);

    struct Node *pHead = NULL;

    for(unsigned int i = 0; i < numberSetSize; i++)
    {
        if(!LinkedListInsert(&pHead, numberSet[i]))
        {
            printf("Error: could not insert element number %d, value %d\n", i, numberSet[i]);
            break;
        }
    }

    printf("Here is the linked list:\n");

    while(pHead && pHead->pNext != NULL)
    {
        printf("%d, ", pHead->value);
        pHead = pHead->pNext;
    }

    printf("%d\n", pHead->value);
}
