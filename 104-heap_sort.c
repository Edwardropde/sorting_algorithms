#include <stdio.h>
#include "sort.h"
/**
 * swap - Swaps two integers
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 */

void swap(int *a, int *b)
{

	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * sift_down - Sifts down the element at index `start` to its proper place
 * @array: The array to be sorted.
 * @start: The starting index.
 * @end: The ending index.
 * @size: The size of the array.
 */

void sift_down(int *array, size_t start, size_t end, size_t size)
{

	size_t root = start;
	size_t child, swap;
	int tmp;

	while (2 * root + 1 <= end)
	{
		child = 2 * root + 1;
		swap = root;
		if (array[swap] < array[child])
			swap = child;
		if (child + 1 <= end && array[swap] < array[child + 1])
			swap = child + 1;
		if (swap == root)
			return;
		tmp = array[root];
		array[root] = array[swap];
		array[swap] = tmp;
		print_array(array, size);
		root = swap;
	}
}

/**
 * heap_sort - Sorts an array of integers in ascending order using heap sort
 * @array: The array to be sorted.
 * @size: The size of the array.
 */

void heap_sort(int *array, size_t size)
{

	size_t i;

	if (!array || size < 2)
		return;
	for (i = size / 2; i > 0; i--)
		sift_down(array, i - 1, size - 1, size);
	for (i = size - 1; i > 0; i--)
	{
		swap(&array[0], &array[i]);
		print_array(array, size);
		sift_down(array, 0, i - 1, size);
	}
}
