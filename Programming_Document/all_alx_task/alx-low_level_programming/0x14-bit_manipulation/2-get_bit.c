#include <stdio.h>

/**
 * get_bit - Function that returns the value of a bit at a given index.
 *
 * @n: The integer
 * @index: The position
 * Return: The bit
 */

int get_bit(unsigned long int n, unsigned int index)
{
	unsigned int bit_num;
	unsigned long int save_bit;
	int bit_amt;

	bit_num = sizeof(unsigned long int) * 8;
	if (index >= bit_num)
	{
		return (-1);
	}
	save_bit = n >> index;

	bit_amt = save_bit & 1UL;

	return (bit_amt);
}
