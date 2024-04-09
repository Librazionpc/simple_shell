#include <stdio.h>
#include "main.h"
/**
 * print_array - Function that print arrays
 *
 * @a: Fetches the argument from the main.c
 * @n: Fetches the argument from the main.c
 */
void print_array(int *a, int n)
{
	int s = 0;

	for (; s < n; s++)
	{
		printf("%d", a[s]);
		if (s < n - 1)
			printf(", ");
	}
	putchar('\n');
}
