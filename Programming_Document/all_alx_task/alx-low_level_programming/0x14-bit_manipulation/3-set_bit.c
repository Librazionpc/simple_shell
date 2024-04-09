#include "main.h"

/**
 * set_bit - Function that sets the value of a bit to 1 at a given index.
 *
 * @n: The integer
 * @index: The position to eb workied on
 * Return: Always 1 (Success)
 */

int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int save = 0;
	unsigned int bit = 0;

	bit = sizeof(unsigned long int) * 8;
	if (index >= bit)
	{
		return (-1);
	}
	save = 1UL << index;

	*n |= save;

	return (1);
}
