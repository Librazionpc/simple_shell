#include <stdio.h>
#include "main.h"

/**
 * _pow_recursion - Function that raise a number to it index
 * @x: Fetches the integer to be raised it index
 *
 * @y: Fetches the index
 *
 * Return: Always the output
 */

int _pow_recursion(int x, int y)
{
	if (y < 0)
		return (-1);
	if (y == 0)
		return (1);
	return (x * _pow_recursion(x, y - 1));
}
