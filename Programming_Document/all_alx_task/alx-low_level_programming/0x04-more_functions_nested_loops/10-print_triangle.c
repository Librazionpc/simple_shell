#include <stdio.h>
#include "main.h"
/**
 * print_triangle - Function that print a triangle
 *
 * @size: Fetches the argument from main.c
 */
void print_triangle(int size)
{
	int a, b, n;

	n = size;

	if (size > 0)
	{
		for (a = 0; a < size; a++)
		{
			for (b = 1; b <= size; b++)
			{
				if (b < n)
				{
					_putchar(' ');
				}
				else
				{
					_putchar('#');
				}
			}
			_putchar('\n');
			n--;
		}
	}
	else
	{
		_putchar('\n');
	}
}
