#include "sort.h"

/**
 * heap_sort - Sorts an array of integers in ascending order
 * using the Heap sort algorithm.
 *
 * @array: the array of ints we want to sort
 * @size: size of the array
 * Return: Nothing.
 */
void heap_sort(int *array, size_t size)
{
	int ite, tmp;

	if (size <= 1)
		return;

	for (ite = (size / 2) - 1; ite >= 0; ite--)
		turn_to_heap(array, size, size, ite);

	for (ite = size - 1; ite >= 0; ite--)
	{
		tmp = array[0];
		array[0] = array[ite];
		array[ite] = tmp;

		if (ite > 0)
			print_array(array, size);

		turn_to_heap(array, size, ite, 0);
	}
}

/**
 * turn_to_heap - Recursively turns array to heap
 *
 * @array: the array of ints we want to sort
 * @size: size of the array
 * @heap: size of the heap
 * @index: index
 * Return: Nothing
 */
void turn_to_heap(int *array, int size, int heap, int index)
{
	int largest = index;
	int left = 2 * index + 1;
	int right = 2 * index + 2;
	int tmp;

	if (left < heap && array[left] > array[largest])
		largest = left;

	if (right < heap && array[right] > array[largest])
		largest = right;

	if (largest != index)
	{
		tmp = array[index];
		array[index] = array[largest];
		array[largest] = tmp;
		print_array(array, size);
		turn_to_heap(array, size, heap, largest);
	}
}
