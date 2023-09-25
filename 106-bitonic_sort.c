#include <stdio.h>
#include "sort.h"
/**
 * bitonic_merge - Merges two subarrays in bitonic order
 * @array: The array to be sorted
 * @size: The size of the array
 * @up: 1 if merging in ascending order, 0 for descending order
 */

void bitonic_merge(int *array, size_t size, int up)
{

	size_t mid = size / 2;
	size_t i;
	int temp;

	if (size > 1)
	{
		for (i = 0; i < mid; i++)
		{
			if ((array[i] > array[i + mid]) == up)
			{
				temp = array[i];
				array[i] = array[i + mid];
				array[i + mid] = temp;
			}
		}
		bitonic_merge(array, mid, up);
		bitonic_merge(array + mid, mid, up);
	}
}

/**
 * bitonic_sort_recursive - Recursively sorts a bitonic sequence
 * @array: The array to be sorted
 * @size: The size of the array
 * @up: 1 if sorting in ascending order, 0 for descending order
 */

void bitonic_sort_recursive(int *array, size_t size, int up)
{

	size_t mid = size / 2;

	if (size > 1)
	{
		bitonic_sort_recursive(array, mid, 1);
		bitonic_sort_recursive(array + mid, mid, 0);
		bitonic_merge(array, size, up);
	}
}

/**
 * bitonic_sort - Sorts an array using the Bitonic sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 */

void bitonic_sort(int *array, size_t size)
{

	bitonic_sort_recursive(array, size, 1);
}
