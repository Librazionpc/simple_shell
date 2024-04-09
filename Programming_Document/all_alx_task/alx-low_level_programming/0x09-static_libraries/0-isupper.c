#include <stdio.h>
#include <ctype.h>
/**
 * _isupper - Function that checks for Uppercase or Lowercase
 *
 * @b: Fectches the argument from main.c
 * Return: Always 0
 */
int _isupper(int b)
{
	if (isupper(b))
	{
		return (1);
	}
	else
	{
		return (0);
	}
	return (0);
}
