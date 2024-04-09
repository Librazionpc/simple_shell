#include <stdio.h>
#include <stdlib.h>
#include "main.h"
/**
 * _abs - function that computes the absolute value of an integer.
 *
 * @j: Fetch the value from main.c and passes it to the funtion
 * Return: Always 0 (Success)
 */
int _abs(int j)
{
	if (j > 0)
	{
		return (j);
	}
	else
	{
		return (j * -1);
	}
}
