#include "sort.h"

/**
 * selection_sort - Sort an array of integers using
 * Selection Sort algorithm
 *
 * @array: Array of integers
 * @size: Size of array
 *
 * Return: No return
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, m;
	int tmp;

	for (i = 0; i < size; i++)
	{
		m = i;
		for (j = i + 1; j < size; j++)
			if (array[m] > array[j])
				m = j;

		if (i != m)
		{
			tmp = array[i];
			array[i] = array[m];
			array[m] = tmp;
			print_array(array, size);
		}
	}
}
