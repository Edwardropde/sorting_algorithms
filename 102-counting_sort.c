#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
/**
 * counting_sort - Sorts an array of integers using counting sort
 * @array: The array to be sorted.
 * @size: The size of the array.
 */

void counting_sort(int *array, size_t size)
{

	int max = array[0];
	size_t i, j;
	int *counting_array, *output_array;

	if (array == NULL || size < 2)
		return;
	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	counting_array = malloc(sizeof(int) * (max + 1));
	if (counting_array == NULL)
		return;
	output_array = malloc(sizeof(int) * size);
	if (output_array == NULL)
	{
		free(counting_array);
		return;
	}
	for (i = 0; i <= max; i++)
		counting_array[i] = 0;
	for (i = 0; i < size; i++)
		counting_array[array[i]]++;
	for (i = 1; i <= max; i++)
		counting_array[i] += counting_array[i - 1];
	for (j = size - 1; j >= 0; j--)
	{
		output_array[counting_array[array[j]] - 1] = array[j];
		counting_array[array[j]]--;
	}
	for (i = 0; i < size; i++)
		array[i] = output_array[i];
	free(counting_array);
	free(output_array);
}
