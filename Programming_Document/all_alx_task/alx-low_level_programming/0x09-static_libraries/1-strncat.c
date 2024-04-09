#include <stdio.h>
#include "main.h"
/**
 * _strncat - Function that concatenate next level
 *
 * @dest: Fetches the argument from main.c
 * @src: Fetches the argument from main.c
 * @n: Fetches the argument from main.c
 *
 * Return: Prints the destination
 */
char *_strncat(char *dest, char *src, int n)
{
	char *pt, *st;
	int a, len = 0;

	pt = dest;
	st = src;
	while (*src != '\0')
	{
		len++;
		src++;
	}

	while (*dest != '\0')
	{
		dest++;
	}

	if (n > len)
		n = len;

	src = st;
	for (a = 0; a < n; a++)
	{
		*dest++ = *src++;
	}

	*dest = '\0';
	return (pt);
}
