#include "sort.h"

/**
 * _swap - func swaps two numbers
 * @a: first number
 * @b: second number
 */
void _swap(int *a, int *b)
{
	int elem = *a;
	*a = *b;
	*b = elem;
}

/**
 * lomuto_partition - Lomuto partition scheme
 * @array: Array of int
 * @size: Size
 * @left: Starting index
 * @right: Ending index
 * Return: Final partition
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivot = array + right;
	int v, u;

	for (u = v = left; v < right; v++)
	{
		if (array[v] < *pivot)
		{
			if (u < v)
			{
				_swap(array + v, array + u);
				print_array(array, size);
			}
			u++;
		}
	}
	if (array[u] > *pivot)
	{
		_swap(array + u, pivot);
		print_array(array, size);
	}

	return (u);
}

/**
 * lomuto_sort - Function recursively sorts the array
 * @array: Array of int
 * @size: Size
 * @left: Starting index
 * @right: Ending index
 */
void lomuto_sort(int *array, int size, int left, int right)
{
	int div;

	if (left < right)
	{
		div = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, div - 1);
		lomuto_sort(array, size, div + 1, right);
	}
}

/**
 * quick_sort - Function sorts array using quicksort
 * @array: Array of int
 * @size: Size
 */
void quick_sort(int *array, int size)
{
	lomuto_sort(array, size, 0, size - 1);
}
