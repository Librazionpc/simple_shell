#include <stdio.h>
#include "main.h"

/**
 * print_sign - Function that prints the sign of a number.
 *
 * @n: Fetch the number from main.c and pass hs a argument to the function
 * Return: Always 0 (Success)
 */

int print_sign(int n)
{
	if (n > 0)
	{
		_putchar('+');
		return (1);
	}
	else if (n == 0)
	{
		_putchar('0');
		return (0);
	}
	else
	{
		_putchar('-');
		return (-1);
	}
}
