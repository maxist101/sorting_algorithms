#include "sort.h"

/**
 * selection_sort - Func runs selection sorts algorithm in ascending order
 * @array: Array
 * @size: Size of array
 */
void selection_sort(int *array, int size)
{
	int u, v, n;
	int elem;

	if (array == NULL || size < 2)
		return;

	for (u = 0; u < size - 1; u++)
	{
		n = u;

		for (v = u + 1; v < size; v++)
		{
			if (array[v] < array[n])
				n = v;
		}

		if (n != u)
		{
			elem = array[u];
			array[u] = array[n];
			array[n] = elem;
			print_array(array, size);
		}
	}
}
