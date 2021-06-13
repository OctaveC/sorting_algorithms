#include "sort.h"

/**
 * cocktail_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Cocktail shaker sort algorithm
 *
 * @list: doubly linked list we want to sort
 * Return: Nothing
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped = 1, advance = 0;
	int beginning = 0, end = 0;
	listint_t *holder;

	if (!list || !(*list) || !(*list)->next)
		return;
	for (holder = *list; holder->next != NULL; holder = holder->next)
		end++;
	holder = *list;
	while (swapped == 1)
	{
		advance = beginning;
		while (advance < end)
		{
			if (holder->n > holder->next->n)
			{
				swap(holder, holder->next, list);
				print_list(*list);
				swapped = 1;
			}
			else
				holder = holder->next;
			advance++;
		}
		advance = end;
		swapped = 0;
		while (advance > beginning)
		{
			if (holder->n < holder->prev->n)
			{
				swap(holder->prev, holder, list);
				print_list(*list);
				swapped = 1;
			}
			else
				holder = holder->prev;
			advance--;
		}
		beginning++;
	}
}

/**
 * swap - Swaps two nodes in a doubly linked list
 *
 * @a: first node
 * @b: second node
 * @list: head of the doubly linked list
 * Return: Nothing
 */
void swap(listint_t *a, listint_t *b, listint_t **list)
{
	listint_t *tmp1, *tmp2;

	if (!a || !b)
		return;

	tmp1 = a->prev;
	tmp2 = b->next;

	if (tmp1 == NULL)
	{
		tmp1 = NULL;
		*list = b;
	}
	else
		tmp1->next = b;

	if (tmp2 == NULL)
		tmp2 = NULL;
	else
		tmp2->prev = a;

	a->next = tmp2;
	a->prev = b;
	b->next = a;
	b->prev = tmp1;
}
