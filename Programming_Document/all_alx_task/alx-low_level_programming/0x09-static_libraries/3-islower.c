#include <stdio.h>
#include "main.h"
#include <ctype.h>
#include <stdlib.h>
/**
 * _islower - Checks for lowercase alphabet
 *
 * @c: Parameter that pases the arguments
 * Return: Always 1 (Lowercase)
 */

int _islower(int c)
{
	if (islower(c))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
