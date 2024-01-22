#include "sort.h"

void _swap(int *a, int *b);
void heapify(int *array, size_t size, size_t base, size_t root);
void heap_sort(int *array, size_t size);

/**
 * _swap - Swaps two integers in memory.
 * @a: The first integer to be swapped.
 * @b: The second integer to be swapped.
 */
void _swap(int *a, int *b)
{
	int elem;

	elem = *a;
	*a = *b;
	*b = elem;
}

/**
 * heapify - Converts an array of integers into a binary heap.
 * @array: An array of integers.
 * @size: The size of the array.
 * @base: The index of the current node.
 * @root: The root node of the current node.
 */
void heapify(int *array, size_t size, size_t base, size_t root)
{
	size_t left, right, large;

	left = 2 * root + 1;
	right = 2 * root + 2;
	large = root;

	if (left < base && array[left] > array[large])
		large = left;
	if (right < base && array[right] > array[large])
		large = right;

	if (large != root)
	{
		_swap(array + root, array + large);
		print_array(array, size);
		heapify(array, size, base, large);
	}
}

/**
 * heap_sort - Sorts an array of integers in ascending order.
 * @array: An array of integers.
 * @size: The size of the array.
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;

	for (i = (size / 2) - 1; i >= 0; i--)
		heapify(array, size, size, i);

	for (i = size - 1; i > 0; i--)
	{
		_swap(array, array + i);
		print_array(array, size);
		heapify(array, size, i, 0);
	}
}
