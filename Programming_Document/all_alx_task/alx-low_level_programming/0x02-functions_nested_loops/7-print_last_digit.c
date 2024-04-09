#include <stdio.h>
#include "main.h"
/**
 * print_last_digit - Function that prints the last digit of a number.
 *
 * @n: Fetch the argument from main.c
 *
 * Return: Always 0
 */

int print_last_digit(int n)
{
	int d;

	if (n < 0)
		d = -1 * (n % 10);
	else
		d = n % 10;

	_putchar((d % 10) + '0');
	return (d % 10);
}
