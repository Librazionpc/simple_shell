#include <stdio.h>
#include "main.h"
/**
 * print_diagsums - Function that print diagonals of a tabulated number
 * @a: Fetches the array from main.c
 * @size: Fetches the array lenght from main.c
 */
void print_diagsums(int *a, int size)
{
	int c, b, l;
	unsigned int sum_1 = 0, sum_2 = 0;

	l = size - 1;

	for (c = 0; c < size; c++)
	{
		for (b = 0; b < size; b++)
		{
			if (c == b)
				sum_1 += *(a + c * size + b);
			if (b == l)
				sum_2 += *(a + c * size + b);
		}
		l--;
	}
	printf("%d, %d\n", sum_1, sum_2);
}
