#include "sort.h"

void _swap(int *a, int *b);
int hoare_split(int *array, size_t size, int left, int right);
void hoare_sort(int *array, size_t size, int left, int right);
void quick_sort_hoare(int *array, size_t size);

/**
 * _swap - Swap two integers in an array.
 * @a: The first integer.
 * @b: The second integer.
 */
void _swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * hoare_split - Order a subset of an array of integers.
 * @array: The array of integers.
 * @size: The size of the array.
 * @left: The starting index of the subset to order.
 * @right: The ending index of the subset to order.
 * Return: The final partition index.
 */
int hoare_split(int *array, size_t size, int left, int right)
{
	int rotate, top, bottom;

	rotate = array[right];
	for (top = left - 1, bottom = right + 1; top < bottom;)
	{
		do {
			top++;
		} while (array[top] < rotate);
		do {
			bottom--;
		} while (array[bottom] > rotate);

		if (top < bottom)
		{
			_swap(array + top, array + bottom);
			print_array(array, size);
		}
	}

	return (top);
}

/**
 * hoare_sort - Implement the quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @left: The starting index of the array partition to order.
 * @right: The ending index of the array partition to order.
 */
void hoare_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = hoare_split(array, size, left, right);
		hoare_sort(array, size, left, part - 1);
		hoare_sort(array, size, part, right);
	}
}

/**
 * quick_sort_hoare - Sort an array of integers in ascending
 * @array: An array of integers.
 * @size: The size of the array.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_sort(array, size, 0, size - 1);
}
