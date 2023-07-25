#include "sort.h"

int lomuto_partition(int *array, int low, int high, size_t size);
void lomuto_sort(int *array, int low, int high, size_t size);
void quick_sort(int *array, size_t size);

/**
 * lomuto_partition - Order a subset of an array of integers according to
 * the lomuto partition scheme (last element as pivot)
 * @array: the unsorted array
 * @low: the lowest index of the partition to sort
 * @high: the highest index of the partition to sort
 * @size: size of the unsorted array
 *
 * Return: index position of the partioned element
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int swap, pivot;
	int i, j;

	pivot = array[high];
	i = low - 1;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				swap = array[i];
				array[i] = array[j];
				array[j] = swap;
				print_array(array, size);
			}
		}
	}
	if (array[high] < array[i + 1])
	{
		swap = array[i + 1];
		array[i + 1] = array[high];
		array[high] = swap;
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * lomuto_sort - Implement the quicksort algorithm through recursion
 * @array: array/partion of array to be sorted
 * @low: lowest index of the partion to sort
 * @high: highest index of the partition to sort
 * @size: size of the array
 */
void lomuto_sort(int *array, int low, int high, size_t size)
{
	int partition;

	if (low < high)
	{
		partition = lomuto_partition(array, low, high, size);
		lomuto_sort(array, low, partition - 1, size);
		lomuto_sort(array, partition + 1, high, size);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order using the Quick
 * sort algorithm
 * @array: unsorted array to be sorted
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, 0, size - 1, size);
}
