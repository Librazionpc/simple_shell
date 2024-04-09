#include <stdio.h>
#include "main.h"
/**
 * puts2 - function that prints every other character of a string,
 * starting with the first character, followed by a new line.
 *
 * @str: Fetches the argument
 */
void puts2(char *str)
{
	int len = 0, a = 0;

	for (; str[len] != '\0'; len++)
	{
	}
	len -= 1;

	for (; a <= len; a += 2)
	{
		_putchar(str[a]);
	}

_putchar('\n');
}
