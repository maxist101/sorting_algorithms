#include "sort.h"

/**
 * range_output - func print a range of elem
 * @array: Array to print
 * @start: Start index
 * @end: End index
 */
void range_output(int *array, int start, int end)
{
	int u;

	for (u = start; u <= end; u++)
	{
		if (u > start)
			printf(", ");
		printf("%d", array[u]);
	}
	printf("\n");
}

/**
 * swap_elem - Func swap two elem
 * @array: Array
 * @i: First element
 * @j: Second element
 * @path: path sorting
 */
void swap_elem(int *array, int i, int j, int path)
{
	int elem;

	if (path == (array[i] > array[j]))
	{
		elem = array[i];
		array[i] = array[j];
		array[j] = elem;
	}
}

/**
 * bitonic_merge - Bitonic merge sequence
 * @array: Array to sort
 * @low: Starting index
 * @size: Size length
 * @path: Sorting path
 * @m: size of array
 */
void bitonic_merge(int *array, int low, int size, int path, const int m)
{
	int u = low, v = size;

	if (size > 1)
	{
		v = size / 2;
		for (u = low; u < low + v; u++)
			swap_elem(array, u, u + v, path);

		bitonic_merge(array, low, v, path, m);
		bitonic_merge(array, low + v, v, path, m);
	}
}

/**
 * r_sort - Func recursively runs bitonic sort
 * @array: Array
 * @low: Starting index
 * @size: Size of length array
 * @path: Sorting direction
 * @m: Size of all array
 */
void r_sort(int *array, int low, int size, int path, const int m)
{
	int v = size;

	if (size > 1)
	{
		if (path == 1)
			printf("Merging [%d/%d] (UP):\n", size, m);
		if (path == 0)
			printf("Merging [%d/%d] (DOWN):\n", size, m);
		range_output(array, low, low + v - 1);

		v = size / 2;
		r_sort(array, low, v, 1, m);

		r_sort(array, low + v, v, 0, m);

		bitonic_merge(array, low, size, path, m);
		if (path == 1)
		{
			printf("Result [%d/%d] (UP):\n", size, m);
			range_output(array, low, low + 2 * v - 1);
		}
		if (path == 0)
		{
			printf("Result [%d/%d] (DOWN):\n", size, m);
			range_output(array, low, low + 2 * v - 1);
		}
	}
}

/**
 * bitonic_sort - Func runs bitonic sort algorithm
 * @array: Array
 * @size: Size
 */
void bitonic_sort(int *array, size_t size)
{
	int top = 1;
	const int m = (int)size;

	if (size < 2 || !array)
		return;

	r_sort(array, 0, (int)size, top, m);
}
