#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order
 * using the Counting sort algorithm.
 *
 * @array: the array of ints we want to sort
 * @size: the size of the array we want to sort
 * Return: Nothing
 */
void counting_sort(int *array, size_t size)
{
	unsigned int ite = 0, count = 0, max = 0;
	int *total, *output;

	if (size <= 1)
		return;

	while (ite < size)
	{
		if (array[ite] > (int)max)
			max = array[ite];
		ite++;
	}
	total = malloc((max + 1) * sizeof(int));
	if (total == NULL)
		return;

	output = malloc(size * sizeof(int));
	if (output == NULL)
	{
		free(total);
		return;
	}
	for (ite = 0; ite < (max + 1); ite++)
	{
		count += how_many(array, size, ite);
		total[ite] = count;
	}
	print_array(total, (max + 1));
	for (ite = 0; ite < size; ite++)
	{
		output[total[array[ite]] - 1] = array[ite];
		total[array[ite]]--;
	}
	for (ite = 0; ite < size; ite++)
	{
		array[ite] = output[ite];
	}
	free(total);
	free(output);
}

/**
 * how_many - Counts how many occurences of a value are present in given array
 *
 * @array: the array we want to count the values of
 * @size: Size of the array
 * @value: The Value we want to count the occurences of
 * Return: The numbers of occurences of the value
 */
int how_many(int *array, size_t size, int value)
{
	unsigned int count = 0, ite = 0;

	for (ite = 0; ite < size; ite++)
	{
		if (array[ite] == value)
			count++;
	}
	return (count);
}
