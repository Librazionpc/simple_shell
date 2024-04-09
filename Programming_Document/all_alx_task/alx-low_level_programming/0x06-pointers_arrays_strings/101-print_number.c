#include <stdio.h>
#include "main.h"
/**
 * print_number - Function that print integers
 *
 * @n: Fetches the integer
 */
void print_number(int n)
{
	int i = n;

	if (n < 0)
	{
		_putchar('-');
		i *= -1;
	}
	if (i / 10)
	{
		print_number(i / 10);
	}
	_putchar(i % 10 + '0');
}
