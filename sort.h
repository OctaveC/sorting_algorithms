#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/**
 * enum kind_e - ???
 *
 * @SPADE: SPADE
 * @HEART: HEART
 * @CLUB: CLUB
 * @DIAMOND: DIAMOND
 */
typedef enum kind_e
{
	SPADE = 0,
	HEART,
	CLUB,
	DIAMOND
} kind_t;

/**
 * struct card_s - Playing card
 *
 * @value: Value of the card
 * From "Ace" to "King"
 * @kind: Kind of the card
 */
typedef struct card_s
{
	const char *value;
	const kind_t kind;
} card_t;

/**
 * struct deck_node_s - Deck of card
 *
 * @card: Pointer to the card of the node
 * @prev: Pointer to the previous node of the list
 * @next: Pointer to the next node of the list
 */
typedef struct deck_node_s
{
	const card_t *card;
	struct deck_node_s *prev;
	struct deck_node_s *next;
} deck_node_t;

/* Mandatory exos prototypes */
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void swap(listint_t *a, listint_t *b, listint_t **list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void quickSort_lomuto(int *array, size_t size, int low, int high);
int separate(int *array, size_t size, int low, int high);

/* Optionals exos prototypes */
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
int how_many(int *array, size_t size, int val);
void merge_sort(int *array, size_t size);
void top_down_split_and_merge(int *array, int *tmp, int start, int end);
void merge(int *tmp, int *array, int start, int middle, int end);
void heap_sort(int *array, size_t size);
void turn_to_heap(int *array, int size, int heap, int index);
void radix_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);
void sort_deck(deck_node_t **deck);

#endif /* SORT_H */
