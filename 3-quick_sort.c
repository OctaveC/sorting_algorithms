#include "sort.h"

/**
 * quick_sort - Sorts an array of integers in ascending order using
 * the Quick sort algorithm.
 *
 * @array: the array we want to sort
 * @size: the size of the array we want to sort
 * Return: Nothing
 */
void quick_sort(int *array, size_t size)
{
	quickSort_lomuto(array, size, 0, size - 1);
}

/**
 * quickSort_lomuto - Recursive function using the lomuto algorythm.
 *
 * @array: the array we want to sort
 * @size: the size of the array we want to sort
 * @low: the lowest int we consider
 * @high: the highest int we consider
 * Return: Nothing
 */
void quickSort_lomuto(int *array, size_t size, int low, int high)
{
	int flag;

	if (low < high)
	{
		flag = separate(array, size, low, high);

		quickSort_lomuto(array, size, low, (flag - 1));

		quickSort_lomuto(array, size, (flag + 1), high);
	}
}

/**
 * separate - Sets a pivot and swaps values.
 *
 * @array: the array we want to sort
 * @size: the size of the array we want to sort
 * @low: the lowest int we consider
 * @high: the highest int we consider
 * Return: Nothing
 */
int separate(int *array, size_t size, int low, int high)
{
	int pivot = array[high];
	int smallest_location = (low - 1);
	int ite, tmp;

	for (ite = low; ite <= high; ite++)
	{
		if (array[ite] <= pivot)
		{
			smallest_location++;
			if (ite != smallest_location)
			{
				tmp = array[smallest_location];
				array[smallest_location] = array[ite];
				array[ite] = tmp;
				print_array(array, size);
			}
		}
	}
	return (smallest_location);
}
