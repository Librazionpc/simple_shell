#include <stdio.h>
#include "main.h"

/**
 * _memcpy - Funtion that copies memory area
 * @dest: Argument to be filled with copied memory
 * @src: Argument to fill the 'dest'
 * @n: Number of bytes
 *
 * Return: The filled 'dest'.
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	char *book = dest;

	while (n--)
	{
		*dest = *src;
		dest++;
		src++;
	}
	return (book);
}
