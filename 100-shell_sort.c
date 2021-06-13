#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order
 * using the Shell sort algorithm, using the Knuth sequence.
 *
 * @array: the array of ints we want to sort
 * @size: the size of the array we want to sort
 * Return: Nothing
 */
void shell_sort(int *array, size_t size)
{
	unsigned int gap = 1, inner, outer;
	int  valueToInsert;

	while (gap < size)
		gap = 3 * gap + 1;

	if (gap >= size)
		gap = (gap - 1) / 3;

	for (; gap > 0; gap = (gap - 1) / 3)
	{
		for (outer = gap; outer < size; outer++)
		{
			valueToInsert = array[outer];
			for (inner = outer; inner > (gap - 1) &&
				     valueToInsert < array[inner - gap]; inner -= gap)
			{
				array[inner] = array[inner - gap];
			}
			array[inner] = valueToInsert;
		}
		print_array(array, size);
	}
}
