#include <stdio.h>

/**
 * get_endianness - Function that checks the endianness.
 *
 * Return: Always 1 (On Success)
 */

int get_endianness(void)
{
	unsigned int _int = 1;
	char *byte;

	byte = (char *)&_int;
	if (*byte == 1)
		return (1);
	else
		return (0);
}
