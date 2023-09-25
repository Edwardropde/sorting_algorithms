#include <stdio.h>
#include "sort.h"
/**
 * swap - Swaps two integers in an array
 * @array: The array containing the integers
 * @a: Index of the first integer
 * @b: Index of the second integer
 */

void swap(int *array, int a, int b)
{

	int temp;

	temp = array[a];
	array[a] = array[b];
	array[b] = temp;
}

/**
 * hoare_partition - Implements the Hoare partition scheme for quicksort
 * @array: The array to be sorted
 * @low: The lowest index of the partition
 * @high: The highest index of the partition
 * @size: The size of the array
 * Return: The index of the pivot element after partitioning
 */

int hoare_partition(int *array, int low, int high, size_t size)
{

	int pivot = array[high];
	int i = low - 1;
	int j = high + 1;

	while (1)
	{
		do {
			i++;
		} while (array[i] < pivot);
		do {
			j--;
		} while (array[j] > pivot);
		if (i < j)
		{
			swap(array, i, j);
			print_array(array, size);
		}
		else
		{
			return (j);
		}
	}
}

/**
 * quicksort_hoare_recursive - Recursive function to perform quicksort
 * @array: The array to be sorted
 * @low: The lowest index of the partition
 * @high: The highest index of the partition
 * @size: The size of the array
 */

void quicksort_hoare_recursive(int *array, int low, int high, size_t size)
{

	int pivot;

	if (low < high)
	{
		pivot = hoare_partition(array, low, high, size);
		if (pivot > low)
			quicksort_hoare_recursive(array, low, pivot, size);
		quicksort_hoare_recursive(array, pivot + 1, high, size);
	}
}

/**
 * quick_sort_hoare - Sorts an array of integers in ascending order
 * @array: The array to be sorted
 * @size: The size of the array
 */

void quick_sort_hoare(int *array, size_t size)
{

	if (array == NULL || size < 2)
		return;
	quicksort_hoare_recursive(array, 0, size - 1, size);
}
