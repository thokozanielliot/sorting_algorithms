#include "sort.h"

/**
 * bubble_sort - Sort an array of integers in ascending
 * order using Bubble Sort algorithm.
 *
 * @array: Array of integers
 * @size: Size of array
 *
 * Return: No return
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, n;
	int tmp, swp;

	for (n = size, swp = 1; n > 0 && swp; n--)
	{
		swp = 0;
		for (i = 0; (i + 1) < n; i++)
		{
			if (array[i] > array[i + 1])
			{
				tmp = array[i + 1];
				array[i + 1] = array[i];
				array[i] = tmp;
				print_array(array, size);
				swp = 1;
			}
		}
	}
}
