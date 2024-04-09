#include <stdio.h>
#include "main.h"
/**
 * _strncpy - Fuction that copies a string
 *
 * @dest: Fetches the destinaition array argument
 * @src: Fetch the string to be copind to the destinati	* on
 * @n: Fetches the amount of characters to print
 *
 * Return: prints destination arrrays
 */
char *_strncpy(char *dest, char *src, int n)
{
	int a = 0;

	if (dest == NULL || src == NULL || n == 0)
	{
		return (dest);
	}

	while (a < n && src[a] != '\0')
	{
		dest[a] = src[a];
		a++;
	}

	while (a < n)
	{
		dest[a] = '\0';
		a++;
	}

	return (dest);
}
