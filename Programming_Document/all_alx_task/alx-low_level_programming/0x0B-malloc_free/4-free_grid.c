#include <stdio.h>
#include <stdlib.h>

/**
 * free_grid - A function that frees a 2D array of ints previously
 * created by your malloc_grid function
 * @grid: Fetches the 2D array of integers to free
 * @height: (Parent array) of grid
 * Return: Always 0 (Success)
 */

void free_grid(int **grid, int height)
{
	int i = 0;

	if (grid == NULL)
		return;
	for (; i < height; i++)
		free((int *)grid[i]);
	free(grid);
}
