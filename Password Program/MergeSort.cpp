#include "MergeSort.h"
#include "User.h"
#include <iostream>
using namespace std;

node* sortedMerge(node* first, node* second)
{
	node* result = NULL; 

	/* Base cases */
	if (first == NULL)
	{
		return (second);
	}
	else if (second == NULL)
	{
		return (first); 
	}



	/* Pick either a or b, and recur */
	if (first->user.getUsername().compare(second->user.getUsername()) < 0)
	{
		result = first;
		result->next = sortedMerge(first->next, second);
	}
	else
	{
		result = second;
		result->next = sortedMerge(first, second->next);
	}
	
	return (result); 
}

/* UTILITY FUNCTIONS */
/* Split the nodes of the given list into first and second halves, and return the two lists using the reference parameters. 
   If the length is odd, the extra node should go in the first list. Uses the fast/slow pointer strategy. */

void splitList(node* source, node** firstRef, node** secondRef)
{
	node* slow = source;
	node* fast = source->next;

	/* Advance 'fast' two nodes, and advance 'slow' one node */
	while (fast != NULL)
	{
		if (fast != NULL)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}

	/* 'slow' is before the midpoint in the list, so split it in two at that point. */
	*firstRef = source;
	*secondRef = slow->next;
	slow->next = NULL;
}

/* Sorts the linked list by changing next pointers (not data) */
void mergeSort(node** headRef)
{
	node* head = *headRef;
	node* first;
	node* second;

	/* Base case -- Length 0 ior 1 */
	if ((head == NULL) || (head->next == NULL))
	{
		return;
	}

	/* Split head into 'first' and 'second' sublists */
	splitList(head, &first, &second);

	mergeSort(&first);
	mergeSort(&second);

		/* answer = merge the two sorted lists together */
		*headRef = sortedMerge(first, second); 
} 

/* Function to print nodes in a given linked list */
void printList(node* node)
{
	while (node != NULL)
	{
		cout << node->user.getUsername() << "/n";
		node = node->next; 
	}
}

/* Function to insert a node at the beginning of the linked list */
void push(node** head_ref, User user)
{
	/* Allocate node */
	node* new_node = new node(user);

	/* Link the old list of the new node */
	new_node->next = (*head_ref);

	/* Move the head to point to the new node */
	(*head_ref) = new_node; 

}

