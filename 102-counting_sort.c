#include "sort.h"

/**
 * counting_sort - Sorts an array of integers using Counting Sort
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void counting_sort(int *array, size_t size);
void counting_sort(int *array, size_t size)
{
	int max, *count, u, *output;
	size_t i;

	if (array == NULL || size < 2)
		return;

	/* Find the maximum value in the array */
	max = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	/* Create a counting array to store the count of each element */
	count = malloc((max + 1) * sizeof(int));
	if (count == NULL)
		return;

	/* Initialize counting array */
	for (u = 0; u <= max; u++)
		count[u] = 0;

	/* Populate counting array with the count of each element */
	for (i = 0; i < size; i++)
		count[array[i]]++;

	/* Convert count[i] to count[i] + count[i-1] */
	for (u = 1; u <= max; u++)
		count[u] += count[u - 1];

	/* Print the counting array */
	print_array(count, max + 1);

	/* Update the original array with sorted values */
	output = malloc(size * sizeof(int));
	for (i = 0; i < size; i++)
	{
		output[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}

	/* Copy the sorted elements into the original array */
	for (i = 0; i < size; i++)
		array[i] = output[i];

	/* Print the sorted array */
	/* print_array(array, size);*/

	/* Free allocated memory */
	free(count);
	free(output);
}
