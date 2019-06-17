/*
This problem was asked by Google.

Given a singly linked list and an integer k, remove the kth last element from the list. k is guaranteed to be smaller than the length of the list.

The list is very long, so making more than one pass is prohibitively expensive.

Do this in constant space and in one pass.
*/

#include <cstdlib>

struct Node
{
	int value;
	Node *next;
};

void RemoveKth(Node *head, unsigned int num)
{
	Node *pCur = head, *pRear = head;

	for(unsigned int i=0; i<=num; i++)
		pCur = pCur->next;

	while(pCur->next)
	{
		pCur = pCur->next;
		pRear = pRear->next;
	}

	Node *deleteMe = pRear->next;
	pRear->next = pRear->next->next;

	free(deleteMe);
}

void DoRemoveFromLinkedList()
{
	Node *p = NULL;
	RemoveKth(p, 6);
}