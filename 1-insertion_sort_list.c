#include <stdio.h>
#include "sort.h"
/**
 * insertion_sort_list - Sorts doubly linked list of int in ascending order
 * @list: Pointer to the head of the linked list.
 * Return: Nothing
 */

void insertion_sort_list(listint_t **list)
{

	listint_t *curr, *prev, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	curr = (*list)->next;
	prev = curr->prev;
	temp = NULL;
	while (curr != NULL)
	{
		temp = curr->next;
		while (prev != NULL && prev->n > curr->n)
		{
			prev->next = curr->next;
			if (curr->next != NULL)
				curr->next->prev = prev;
			curr->next = prev;
			curr->prev = prev->prev;
			prev->prev = curr;
			if (curr->prev != NULL)
				curr->prev->next = curr;
			else
				*list = curr;
			print_list(*list);
			prev = curr->prev;
		}
		curr = temp;
		if (temp != NULL)
			prev = temp->prev;
	}
}
