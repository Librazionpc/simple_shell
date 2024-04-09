#include "search_algos.h"
/**
 * linear_search - Function that use linearSearch algorithms to fetch the values needed
 * @array: Array that hold the integer to be checked
 * @size: The size of the array
 *
 */

int linear_search(int *array, size_t size, int value)
{
	int cmp;
	size_t i;

	if (array == NULL)
		return (-1);

	for (i = 0; i < size; i++)
	{
		cmp = array[i];
		printf("Value cheacked array[%ld] = [%d]\n", i, array[i]);
		if (cmp == value)
			return (i);
	}

	return (-1);
}
