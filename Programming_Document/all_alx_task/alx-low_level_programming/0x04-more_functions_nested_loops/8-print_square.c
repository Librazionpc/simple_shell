#include "main.h"

/**
 * print_square - Function that prints a square
 * @size: Fetches the argument from main.c
 */
void print_square(int size)
{
	int a = 0, b;

	if (size > 0)
	{
		for (; a < size; a++)
		{
			for (b = 0; b < size; b++)
				_putchar('#');
			_putchar('\n');
		}
	}
	else
		_putchar('\n');
}
