#include "sort.h"

/**
 * merge_sort - Sorts an array of integers in ascending order
 * using the Merge sort algorithm.
 *
 * @array: the array of ints we want to sort
 * @size: the size of the array we want to sort
 * Return: Nothing
 */
void merge_sort(int *array, size_t size)
{
	int *tmp;

	if (size <= 1)
		return;

	tmp = malloc((size + 1) * sizeof(int));
	if (tmp == NULL)
		return;

	top_down_split_and_merge(array, tmp, 0, size - 1);
	free(tmp);
}

/**
 * top_down_split_and_merge - Calls merge_sort recursively
 *
 * @array: the array of ints we want to sort
 * @tmp: a copy of array
 * @start: the start of our array
 * @end: the end of our array
 * Return: Nothing
 */
void top_down_split_and_merge(int *array, int *tmp, int start, int end)
{
	int middle;

	if (start < end)
	{
		middle = ((end + start - 1) / 2);
		top_down_split_and_merge(array, tmp, start, middle);
		top_down_split_and_merge(array, tmp, middle + 1, end);
		merge(array, tmp, start, middle, end);
	}
}

/**
 * merge - Merges the whole mess together
 *
 * @array: the array of ints we want to sort
 * @tmp: a copy of array
 * @start: the start of our array
 * @middle: the middle of our array
 * @end: the end of our array
 * Return: Nothing
 */
void merge(int *array, int *tmp, int start, int middle, int end)
{
	int ite = 0, ite2 = 0, ite3 = 0, ite4 = 0;
	int left[4096], right[4096];
	int s_copy = start;
	int m_copy = middle + 1;

	printf("Merging...\n");
	while (s_copy <= middle && m_copy <= end)
	{
		if (array[s_copy] <= array[m_copy])
		{
			tmp[ite] = left[ite2] = array[s_copy];
			ite++, ite2++, s_copy++;
		}
		else
		{
			tmp[ite] = right[ite3] = array[m_copy];
			ite++, ite3++, m_copy++;
		}
	}
	while (s_copy <= middle)
		tmp[ite] = left[ite2] = array[s_copy], ite++, ite2++, s_copy++;
	while (m_copy <= end)
		tmp[ite] = right[ite3] = array[m_copy], ite++, ite3++, m_copy++;
	printf("[left]: ");
	for (ite4 = 0; ite4 < ite2; ite4++)
		(ite4 == 0) ? printf("%d", left[ite4]) : printf(", %d", left[ite4]);
	printf("\n[right]: ");
	for (ite4 = 0; ite4 < ite3; ite4++)
		(ite4 == 0) ? printf("%d", right[ite4]) : printf(", %d", right[ite4]);
	printf("\n[Done]: ");
	for (s_copy = start; s_copy <= end; s_copy++)
	{
		array[s_copy] = tmp[s_copy - start], printf("%d", array[s_copy]);
		if (s_copy != end)
			printf(", ");
		else
			printf("\n");
	}
}
