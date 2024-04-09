#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * create_array - Function that create a arrays of characters
 * and initials and specific characters
 *
 * @size: Fetches the size that is to be allocated to HEEP SEGMENT
 * @c: Fetches the character to filled in that memory
 *
 * Return: The memory with the Filled Array
 *
 */

char *create_array(unsigned int size, char c)
{
	unsigned int i;
	char *pt_array;

	if (size == 0)
		return (NULL);
	pt_array = (char *)malloc(sizeof(char) * size);
	if (pt_array == NULL)
		return (NULL);
	for (i = 0; i < size; i++)
		pt_array[i] = c;
	return (pt_array);
}
