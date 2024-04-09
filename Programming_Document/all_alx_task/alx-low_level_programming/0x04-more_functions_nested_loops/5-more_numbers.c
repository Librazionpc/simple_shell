#include <stdio.h>
#include "main.h"
/**
 * spacing_format - Function that print the arguments passed for more_numbers
 * passed in and also format it
 *
 * @n: it fetches the argument from more_numbers
 *
 * Return: Always 0
 */
int spacing_format(int n)
{
	if (n > 9)
	{
		_putchar((n / 10) + '0');
	}
	_putchar((n % 10) + '0');
	return (0);
}

/**
 * more_numbers - Funtion that print 0 - 14 x 10 times
 */
void more_numbers(void)
{
	int a, b;

	for (a = 0; a < 10; a++)
	{
		for (b = 0; b <= 14; b++)
		{
			spacing_format(b);
		}
		_putchar('\n');
	}
}
