#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * array_range - Funtion that creates an array of integer
 *
 * @min: Fetches the lowest int from main.c
 * @max: Fetches the highest int from main.c
 *
 * Return: The arrays
 *
 */

int *array_range(int min, int max)
{
	int a, diff, *pt_array;

	if (min > max)
		return (NULL);
	diff = max - min;
	pt_array = malloc(sizeof(int) * (diff + 1));
	if (pt_array == NULL)
		return (NULL);
	for (a = 0; a <= diff; a++)
		pt_array[a] = min + a;
	return (pt_array);
}
