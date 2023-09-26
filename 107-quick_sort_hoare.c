#include "sort.h"

/**
 * swap - swap variables
 * @a: var a
 * @b: var b
 */
void swap(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}
/**
 * hoare_partition - sort an algorithm
 * @array: array to sort from
 * @low: first element
 * @high: last element
 * Return: j
 */
int hoare_partition(int *array, int low, int high)
{
	int pivot = array[high];
	int i = low - 1;
	int j = high + 1;

	while (1)
	{
		do {
			i++;
		} while (array[i] < pivot);
		do {
			j--;
		} while (array[j] > pivot);
		if (i >= j)
		{
			return (j);
		}
		swap(&array[i], &array[j]);
	}
}
/**
 * quick_sort_hoare - sort an algorithm quickly
 * @array: array to sort from
 * @size: size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
	int low = 0;
	int high = size - 1;
	int *stash = (int *)malloc(2 * size * sizeof(int));
	int above = -1;
	int pivot_index;

	if (size <= 1)
	{
		return;
	}
	stash[++above] = low;
	stash[++above] = high;
	while (above >= 0)
	{
		high = stash[above--];
		low = stash[above--];
		pivot_index = hoare_partition(array, low, high);
		if (pivot_index - 1 > low)
		{
			stash[++above] = low;
			stash[++above] = pivot_index - 1;
		}
		if (pivot_index + 1 < high)
		{
			stash[++above] = pivot_index + 1;
			stash[++above] = high;
		}
	}
	free(stash);
}
