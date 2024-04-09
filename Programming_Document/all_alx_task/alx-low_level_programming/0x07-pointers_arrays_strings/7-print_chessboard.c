#include <stdio.h>
#include "main.h"

/**
 * print_chessboard - function that print the chessboard
 * @a: fetches the argument from main.c
 *
 * Return: The printed chess board
 */
void print_chessboard(char (*a)[8])
{
	int c = 0, b = 0;
	char ans;

	for (c = 0; c < 8; c++)
	{
		for (b = 0; b < 8; b++)
		{
			ans = a[c][b];
			_putchar(ans);
		}
		_putchar('\n');
	}
}
