#include <stdio.h>

/**
 * flip_bits - function that returns the number of bits you
 * would need to flip to get from one number to another.
 *
 * @n: The integer
 * @m: flip integer
 *
 * Return: The results
 *
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int xorRes;
	unsigned int count = 0;

	xorRes = n ^ m;
	while (xorRes)
	{
		count += xorRes & 1;
		xorRes >>= 1;
	}

	return (count);
}
