#include "sort.h"

/**
 * bubble_sort - Sorts Integers's array in ascending order
 * order using the Bubble sort
 * @array: array of integers
 * @size: size of array
 * Return: sorted array
 */

void bubble_sort(int *array, size_t size)
{
	int aux = 0, sw = 1;
	unsigned int j = 0;

	if (array == NULL || size < 2)
		return;

	while (sw != 0)
	{
		sw = 0;
		for (j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				aux = array[j];
				array[j] = array[j + 1];
				array[j + 1] = aux;
				sw = 1;
				print_array(array, size);
			}
		}
	}
}
