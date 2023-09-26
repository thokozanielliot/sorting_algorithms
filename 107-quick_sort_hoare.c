#include "sort.h"
#include <stdio.h>

/**
 * swap - swap variables
 * @a: first letter
 * @b: second letter
 */
void swap(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}

/**
 * hoare_partition - sorts algorithm quick
 * @array: array to sort from
 * @low:  low array
 * @high: top array
 * Return: j
 */
int hoare_partition(int *array, int low, int high)
{
	int pivot = array[high];
	int i = low - 1;
	int j = high + 1;
	int k;

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
	}
	swap(&array[i], &array[j]);
	
	for (k = low; k <= high; k++)
	{
		printf("%d ", array[k]);
	}
	printf("\n");
}

/**
 * quick_sort_hoare - function that sorts the algorithm quick
 * @array: array to sort from
 * @high: high array
 * @low: low array
 */
void quick_sort_hoare(int *array, int low, int high)
{
	int pivot_index;

	if (low < high)
	{
		pivot_index = hoare_partition(array, low, high);
		quick_sort_hoare(array, low, pivot_index);
		quick_sort_hoare(array, pivot_index + 1, high);
	}
}
