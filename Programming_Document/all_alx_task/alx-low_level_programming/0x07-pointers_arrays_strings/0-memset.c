#include <stdio.h>
#include "main.h"
/**
 * _memset - Function that fills memory with a constant byte
 *
 * @s: argument to be filled
 * @b: argumenet that fills 's'
 * @n: Number of byte
 *
 * Return: The byte stored in 'book'
 */
char *_memset(char *s, char b, unsigned int n)
{
	char *book = s;

	while (n--)
	{
		*s = b;
		s++;
	}
	return (book);
}
