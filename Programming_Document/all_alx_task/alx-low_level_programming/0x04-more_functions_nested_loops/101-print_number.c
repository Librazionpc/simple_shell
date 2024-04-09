#include "main.h"
/**
 *
 * print_integer - Function that primt integers
 * @a: Fetches the argument
 * Return: Always 0
 */
void print_integer(int a)
{
	int b = 1000000000;

	for (; b >= 1; b /= 10)
	{
		if ((a / b) != 0)
		{
	  			_putchar((a / b) % 10 + '0');
		}
	}
}

/**
 * print_number - a function that prints an integer.
 * @n: An input integer
 * Return: Nothing
 */
void print_number(int n)
{
	if (n == 0)
		_putchar('0');
	else if (n < 0)
	{
		_putchar('-');
		print_integer(n * -1);
	}
	else
		print_integer(n);
}

