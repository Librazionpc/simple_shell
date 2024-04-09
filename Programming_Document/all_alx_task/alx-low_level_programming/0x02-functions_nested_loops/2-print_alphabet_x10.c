#include <stdio.h>
#include "main.h"

/**
 * print_alphabet_x10 - printing lowercase alphabet [a..z] x10
 *
 * Return: Always 0
 */
void print_alphabet_x10(void)
{
	char a, low;

	for (a = 0; a < 10; a++)
	{
		for (low = 'a'; low <= 'z'; low++)
		{
			_putchar(low);
		}
	_putchar('\n');
	}
}
