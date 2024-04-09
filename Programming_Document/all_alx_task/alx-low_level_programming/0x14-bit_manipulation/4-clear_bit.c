#include <stdio.h>

/**
 * clear_bit - Function that sets the value of a bit to 0 at a given index
 * @n: The integer
 * @index: The postion to be worked on
 *
 * Return: Always 1 (Success)
 */

int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned int bit = 0;
	unsigned long int mask = 0;

	bit = sizeof(unsigned long int) * 8;
	if (index >= bit)
	{
		return (-1);
	}
	mask = ~(1UL << index);
	*n &= mask;

	return (1);
}
