#include <stdio.h>
#include "main.h"
/**
 * print_binary - Function that prints the binary representation of a number.
 * @n: The integer
 *
 * Return: Nothing
 */

void print_binary(unsigned long int n)
{
	int next = 0, check = 1, bits = 0;
	unsigned long int save = 0;

	next = sizeof(n) * 8 - 1;
	while (next >= 0)
	{
		save = 1UL << next;
		bits = (n & save) ? 1 : 0;

		if (bits || !check)
		{
			_putchar('0' + bits);
			check = 0;
		}

		next--;
	}

	if (check)
	{
		_putchar('0');
	}
}
