#include "sort.h"

void quick_sort(int *array, size_t size);
void _qsort(int *a, int low, int high, int size);

/**
 * quick_sort - Sort an array of integers in ascending
 * order using Quick Sort algorithm
 *
 * @array: Array of integers
 * @size: Size of array
 *
 * Retunr: No return
 */
void quick_sort(int *array, size_t size)
{
	_qsort(array, 0, size - 1, size);
}

/**
 * _qsort - Quick Sort function
 *
 * @a: Array of integres
 * @low: Index o f first element
 * @high: Index of last element
 * @size: Size of array
 *
 * Return: No Return
 */
void _qsort(int *a, int low, int high, int size)
{
	int p, w, i;
	int tmp;

	if (low < high)
	{
		p = high;
		w = low;

		for (i = low; i < high; i++)
		{
			if (a[i] < a[p])
			{
				if (i != w)
				{
					tmp = a[i];
					a[i] = a[w];
					a[w] = tmp;
					print_array(a, size);
				}
				w++;
			}
		}

		if (w != p && a[w] != a[p])
		{
			tmp = a[w];
			a[w] = a[p];
			a[p] = tmp;
			print_array(a, size);
		}
		_qsort(a, low, w - 1, size);
		_qsort(a, w + 1, high, size);
	}
}
