#include <stdio.h>
#include "main.h"
/**
 * swap_int - Function that swaps the values of two integers.
 *
 * @a: fetches the argument from the main.c
 * @b: fetches the argument from the main.c
 *
 */
void swap_int(int *a, int *b)
{
	int d;

	d = *a;
	*a = *b;
	*b = d;
}
