#include <stdio.h>
#include "main.h"

/**
 * _puts_recursion - Function that write a string with a trailing to stdout.
 *
 * @s: Fetches the argument that is the string
 *
 */

void _puts_recursion(char *s)
{
	if (*s == '\0')
	{
		_putchar('\n');
		return;
	}

	_putchar(*s);
	s++;
	_puts_recursion(s);
}
