#include "sort.h"

/**
 * _swap - func swaps two numbers
 * @a: first number
 * @b:  second number
 */
void _swap(int *a, int *b)
{
	int elem = *a;
	*a = *b;
	*b = elem;
}

/**
 * bubble_sort - Func sorts an ARR of num using bubble sort algorithm
 * @array: Array being sorted
 * @size: Array size
 *
 * Return: void
 */
void bubble_sort(int *array, int size)
{
	int u, v, pri_v;

	v = size;

	if (array == NULL || size < 2)
		return;

	while (v > 0)
	{
		pri_v = 0;
		for (u = 0; u < v - 1; u++)
		{
			if (array[u] > array[u + 1])
			{
				_swap(&array[u], &array[u + 1]);
				pri_v = u + 1;
				print_array(array, size);
			}
		}
		v = pri_v;
	}
}
