#include <stdio.h>
#include "main.h"

/**
 * factorial - Function that returns the factorial of a given function
 *
 * @n: Detche the argument from main.c
 *
 * Return: The factorial has output.
 */

int factorial(int n)
{
	if (n < 0)
	{
		return (-1);
	}
	else if (n == 0)
	{
		return (1);
	}
	return (n * factorial(n - 1));
}
