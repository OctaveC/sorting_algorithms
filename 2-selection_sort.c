#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order using
 * the Selection sort algorithm.
 *
 * @array: the array we want to sort
 * @size: the size of the array we want to sort
 * Return: Nothing
 */
void selection_sort(int *array, size_t size)
{
	unsigned int i, j, min, tmp;

	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
				min = j;
		}
		if (min != i)
		{
			tmp = array[i];
			array[i] = array[min];
			array[min] = tmp;

			print_array(array, size);
		}
	}
}
