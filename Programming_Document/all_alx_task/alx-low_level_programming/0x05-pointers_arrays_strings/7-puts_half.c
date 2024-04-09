#include <stdio.h>
#include "main.h"
/**
 * puts_half - Function that prints half of a string,
 * followed by a new line.
 *
 * @str: Fetches the argumen from main.c
 */
void puts_half(char *str)
{
	int n, a, len;

	for (len = 0; str[len] != '\0'; len++)
	{
	}
	if ((len % 2) != 0)
	{
		n = len - 1 / 2;
	}
	else
	{
		n = len / 2;
	}

	for (a = n; a < len; a++)
	{
		_putchar(str[a]);
	}
_putchar('\n');
}
