#include <stdlib.h>
#include "main.h"

/**
 * _calloc - Function that create in malloc
 *
 * @nmemb: Fetches the argument for the arrayt from main.c
 * @size: Fetches the size of the data type
 *
 * Return: The array
 *
 */

void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *pt_array;
	unsigned int a;

	if (size == 0 || nmemb == 0)
		return (NULL);

	pt_array = malloc(size * nmemb);
	if (pt_array == NULL)
		return (NULL);
	for (a = 0; a < (nmemb * size); a++)
		pt_array[a] = 0;
	return ((void *)pt_array);
}
