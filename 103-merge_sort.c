#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * join_subarray - Func joins two subarray
 * @array: main array
 * @temp: temp array
 * @left: starting index
 * @mid: middle index
 * @right: ending index
 */
void join_subarray(int *array, int *temp, size_t left,
		size_t mid, size_t right);
void join_subarray(int *array, int *temp, size_t left,
		size_t mid, size_t right)
{
	size_t u = left, v = mid, w = left;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + left, mid - left);
	printf("[right]: ");
	print_array(array + mid, right - mid);

	while (u < mid && v < right)
	{
		if (array[u] <= array[v])
		{
			temp[w] = array[u];
			u++;
		}
		else
		{
			temp[w] = array[v];
			v++;
		}
		w++;
	}
	while (u < mid)
	{
		temp[w] = array[u];
		u++;
		w++;
	}
	while (v < right)
	{
		temp[w] = array[v];
		v++;
		w++;
	}
	for (w = left; w < right; w++)
	{
		array[w] = temp[w];
	}
	printf("[Done]: ");
	print_array(array + left, right - left);
}

/**
 * join_sort - recursive func that runs merge sort
 * @array: main array
 * @temp: temporary array
 * @left: starting index
 * @right: ending index
 */
void join_sort(int *array, int *temp, size_t left, size_t right)
{
	size_t centre;

	if (right - left < 2)
	{
		return;
	}

	centre = left + (right - left) / 2;

	join_sort(array, temp, left, centre);
	join_sort(array, temp, centre, right);
	join_subarray(array, temp, left, centre, right);
}

/**
 * merge_sort - Func initiate merge sort algorithm
 * @array: Array
 * @size: Size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *elem;

	if (array == NULL || size < 2)
	{
		return;
	}

	elem = malloc(sizeof(*elem) * size);
	if (elem == NULL)
	{
		return;
	}

	join_sort(array, elem, 0, size);

	free(elem);
}
