#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order
 * using the Selection sort algorithm
 * @array: the array to be sorted
 * @size: the size of the array
*/
void selection_sort(int *array, size_t size)
{
	size_t position = 0, i, j;
	int tmp;

	for (i = 0; i < size - 1; i++)
	{
		position = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[position])
				position = j;
		}
		if (position != i)
		{
			tmp = array[i];
			array[i] = array[position];
			array[position] = tmp;
			print_array(array, size);
		}
	}
}
