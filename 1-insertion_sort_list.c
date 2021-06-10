#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 *
 * @list: doubly linked list we want to sort
 * Return: Nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *new_node;

	if (!list || !(*list) || !(*list)->next)
		return;

	new_node = *list;

	while (new_node != NULL)
	{
		while (new_node->prev != NULL && new_node->n < new_node->prev->n)
		{
			swap(new_node->prev, new_node, list);
			print_list(*list);
		}
		new_node = new_node->next;
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
