#include "sort.h"



int partition_hoare(int *array, size_t size, int low, int high)
{
    int tmp, pivot, left_index, right_index;

    pivot = array[high];

    left_index = low - 1;
    right_index = high + 1;

    while (1)
    {
        do {
            left_index++;
        } while (array[left_index] < pivot);

        do {
            right_index--;
        } while (array[right_index] > pivot);

        if (left_index >= right_index)
            return (left_index);

        if (left_index != right_index)
        {
            tmp = array[left_index];
            array[left_index] = array[right_index];
            array[right_index] = tmp;
        }

        print_array(array, size);
    }
}

void quicksort_hoare(int *array, size_t size, int low, int high)
{
    int pivot;

    if (low < high)
    {
        pivot = partition_hoare(array, size, low, high);

        quicksort_hoare(array, size, low, pivot - 1);
        quicksort_hoare(array, size, pivot, high);
    }
}

void quick_sort_hoare(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    quicksort_hoare(array, size, 0, size - 1);
}

