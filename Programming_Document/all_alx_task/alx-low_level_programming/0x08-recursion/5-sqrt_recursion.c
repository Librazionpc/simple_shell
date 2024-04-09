#include <stdio.h>
#include "main.h"

/**
 * _sqrt - Funtion that calculate the sqrt of a number
 *
 * @number: Fetches the number to square rooted
 * @root: Fetches the argument to check for the integer that will @number
 *
 * Return: Always the result
 */
int _sqrt(int number, int root)
{
	if ((root * root) > number)
		return (-1);
	else if ((root * root) == number)
		return (root);
	else
		return (_sqrt(number, root + 1));
}

/**
 * _sqrt_recursion - Funtons that returns the natural squart
 * @n: Fetches the argument
 *
 * Return: The natural sqrt
 */

int _sqrt_recursion(int n)
{
	if  (n < 0)
		return (-1);
	return (_sqrt(n, 0));
}
