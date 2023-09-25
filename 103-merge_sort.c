#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
/**
 * merge - Merges two sub-arrays of array[].
 * @array: Pointer to the main array.
 * @left: Pointer to the left sub-array.
 * @left_size: Size of the left sub-array.
 * @right: Pointer to the right sub-array.
 * @right_size: Size of the right sub-array.
 */

void merge(int *array, int *left, size_t left_size,
		int *right, size_t right_size)
{

	size_t i = 0, j = 0, k = 0;
	int *temp = malloc((left_size + right_size) * sizeof(int));

	if (!temp)
		return;
	printf("Merging...\n[left]: ");
	print_array(left, left_size);
	printf("[right]: ");
	print_array(right, right_size);
	while (i < left_size && j < right_size)
	{
		if (left[i] <= right[j])
			temp[k++] = left[i++];
		else
			temp[k++] = right[j++];
	}
	while (i < left_size)
		temp[k++] = left[i++];
	while (j < right_size)
		temp[k++] = right[j++];
	for (i = 0; i < left_size + right_size; i++)
		array[i] = temp[i];
	printf("[Done]: ");
	print_array(array, left_size + right_size);
	free(temp);
}

/**
 * merge_sort - Sorts an array of integers in ascending order using merge sort
 * @array: Pointer to the array to be sorted.
 * @size: Size of the array.
 */

void merge_sort(int *array, size_t size)
{

	size_t mid = size / 2;
	int *left = array;
	int *right = array + mid;
	size_t left_size = mid;
	size_t right_size = size - mid;

	if (size > 1)
	{
		printf("Merging...\n[left]: ");
		print_array(left, left_size);
		printf("[right]: ");
		print_array(right, right_size);
		merge_sort(left, left_size);
		merge_sort(right, right_size);
		merge(array, left, left_size, right, right_size);
	}
}
