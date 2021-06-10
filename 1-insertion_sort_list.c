#include "sort.h"

void swap(listint_t *a, listint_t *b)
{
	listint_t *tmp1, *tmp2;

	tmp1 = a->prev;
	tmp2 = b->next;

	if (tmp1 == NULL)
		new_node->prev = NULL;
	else
		new_node->prev->prev;

	if (new_node->next == NULL)
		new_node->prev->next = NULL;
	else
		new_node->prev->prev = new_node;

	a->next = tmp2;
	a->prev = b;
	b->next = a;
	b->prev = tmp1;
}

void insertion_sort_list(listint_t **list)
{
	listint_t *;

	new_node = (*list)->next;

	while (new_node->n > new_node->prev->n)
	{
	}

	*list = tmp1;
}
