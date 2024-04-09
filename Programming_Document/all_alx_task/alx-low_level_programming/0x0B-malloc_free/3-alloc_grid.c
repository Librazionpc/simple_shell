#include <stdio.h>
#include <stdlib.h>

/**
 * alloc_grid - Function that returns a pointer to two dimensional
 * arrays
 *
 * @width: Fetches the width of the array (child array)
 * @height: Fetches the height of the array (parent array)
 *
 * Return: The 2 dimensional array
 */

int **alloc_grid(int width, int height)
{
	int i;
	int **pt_parnt_2d_array;

	if (width <= 0 || height <= 0)
		return (NULL);

	pt_parnt_2d_array = (int **)(malloc(sizeof(int *) * height));

	if (pt_parnt_2d_array == NULL)
		return (NULL);

	for (i = 0; i < height; i++)
		pt_parnt_2d_array[i] = (int *)(malloc(sizeof(int) * width));

	if (pt_parnt_2d_array == NULL)
		return (NULL);
	return (pt_parnt_2d_array);
}
