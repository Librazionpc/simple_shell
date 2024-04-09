#include "main.h"
#include <stdio.h>

/**
 * binary_to_uint - Function that convert binary to unint
 * @b: The argument
 *
 * Return: Unsigned int
 */

unsigned int binary_to_uint(const char *b)
{
	unsigned int bin = 0;
	int i = 0;

	if (b == NULL)
		return (0);

	while (b[i] != '\0')
	{
		if (b[i] == '0')
		{
			bin = bin << 1;
		}
		else if (b[i] == '1')
		{
			bin = (bin << 1) | 1;
		}
		else
		{
			return (0);
		}

		i++;
	}
	return (bin);
}
