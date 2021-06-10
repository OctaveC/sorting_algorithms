#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in ascending order using
 * the Bubble sort algorithm.
 *
 * @array: the array we want to sort
 * @size: the size of the array we want to sort
 * Return: Nothing
 */
void bubble_sort(int *array, size_t size)
{
	unsigned int a, swap, ite, ite2;

	if (size <= 1)
		return;

	for (swap = 0, ite = 0; swap != 1; ite++)
	{
		swap = 1;
		for (ite2 = 0; ite2 < size - 1; ite2++)
		{
			if (array[ite2] > array[ite2 + 1])
			{
				a = array[ite2];
				array[ite2] = array[ite2 + 1];
				array[ite2 + 1] = a;
				swap = 0;
				print_array(array, size);
			}
		}
	}
}
