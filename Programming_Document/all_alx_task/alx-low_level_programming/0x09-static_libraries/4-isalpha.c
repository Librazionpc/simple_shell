#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "main.h"
/**
 * _isalpha - Fucntion that checks for Uppercase alphabet
 *
 * @c: Fetch the argument passe to the function
 * Return: Always 1 (Success)
 */
int _isalpha(int c)
{
	if (isupper(c) || islower(c))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
