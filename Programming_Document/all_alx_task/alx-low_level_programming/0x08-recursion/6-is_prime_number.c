#include <stdio.h>
#include "main.h"

/**
 * _prime_checker - Function that checks for prime numbers
 *
 * @number: The argument from main.c that is the number
 *
 * Return: Always 1 (is_prime)
 */
int _prime_checker(int number)
{
	if (number < 0)
		number *= -1;
	if (number == 1)
		return (0);
	else if (number % 2 == 0 || number % 3 == 0 || number % 5 == 0
			|| number % 7 == 0 || number % 11 == 0)
		return (0);
	else
		return (1);
}

/**
 * is_prime_number - Funtion that checks for prime number
 * @n: Fetches the argument from main.c
 *
 * Return: Always 1 (Success)
 */

int is_prime_number(int n)
{
	return (_prime_checker(n));
}
