#include <stdio.h>
#include "main.h"
/**
 * _puts - Function that prints a string using puts,
 * followed by a new line, to stdout.
 *
 * @str: Fetches the output from main.c.
 */
void _puts(char *str)
{
	int a;
	char word;

	for (a = 0; str[a] != '\0'; a++)
	{
		word = str[a];
		_putchar(word);
	}
_putchar('\n');
}
