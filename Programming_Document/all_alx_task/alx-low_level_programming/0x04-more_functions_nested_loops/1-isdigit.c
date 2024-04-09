#include <stdio.h>
#include <ctype.h>

/**
 * _isdigit - Fuction that checks for digit from 0 - 9
 *
 * @c: Fetches argument from main.c
 *
 * Return: Always 0
 */
int _isdigit(int c)
{
	if (isdigit(c))
	{
		return (1);
	}
	else
	{

		return (0);
	}
	return (0);
}
