#include <stdio.h>
#include "main.h"
/**
 * print_line - Funtion that print line
 *
 * @n: Fetches the argument for main.c
 *
 */
void print_line(int n)
{
	int a = 0;

	if (n > 0)
	{
		for (; a < n; a++)
		{
			_putchar('_');
		}
	}
	_putchar('\n');

}
