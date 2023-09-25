#include <stdio.h>
#include "sort.h"

void swap_ints(int *a, int *b);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */

void swap_ints(int *a, int *b)
{

	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * lomuto_partition - Partitions an array using the Lomuto scheme
 * @array: The array to be partitioned.
 * @low: The low index of the partition.
 * @high: The high index of the partition.
 * @size: The size of the array.
 * Return: The index of the pivot element.
 */

int lomuto_partition(int *array, int low, int high, size_t size)
{

	int *pivot, above, below;

	pivot = array + right;
	for (above = below = left; below < right; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swap_ints(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}
	if (array[above] > *pivot)
	{
		swap_ints(array + above, pivot);
		print_array(array, size);
	}
	return (above);
}

/**
 * lomuto_sort - Implement the quicksort algorithm through recursion
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @left: The starting index of the array partition to order.
 * @right: The ending index of the array partition to order.
 */

void lomuto_sort(int *array, size_t size, int left, int right)
{

	int part;

	if (right - left > 0)
	{
		part = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, part - 1);
		lomuto_sort(array, size, part + 1, right);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending ordermusing quick sort
 * @array: The array to be sorted.
 * @size: The size of the array.
 */

void quick_sort(int *array, size_t size)
{

	if (array == NULL || size < 2)
		return;
	lomuto_sort(array, size, 0, size - 1);
}
