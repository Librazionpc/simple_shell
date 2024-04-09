#include <stdio.h>
#include <time.h>
#include "main.h"
/**
 * print_numbers - Function prints number from 0 - 9
 *
 */
void print_numbers(void)
{
	int a;

	for (a = 0; a <= 9; a++)
	{
		_putchar(a + '0');
	}
	_putchar('\n');
}
