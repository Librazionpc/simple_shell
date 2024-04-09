#include <stdio.h>
#include "main.h"
/**
 * reverse_array - Function that reverse integers
 *
 * @a: Fetches the integer
 * @n: Fetches the lenght of integer
 */
void reverse_array(int *a, int n)
{
	int j = 0;
	int word;

	while (j < n--)
	{
		word = a[j];
		a[j++] = a[n];
		a[n] = word;
	}
}
