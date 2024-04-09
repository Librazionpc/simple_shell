#include <stdio.h>

/**
 * _atoi - Function that converts string to integer
 * @s: Fetches the argument
 * Return: integer from conversion
 */
int _atoi(char *s)
{
	int sign = 1;
	unsigned int total = 0;
	char break_signal = 0;

	while (*s)
	{
		if (*s == '-')
			sign *= -1;

		if (*s >= '0' && *s <= '9')
		{
			break_signal = 1;
			total = total * 10 + *s - '0';
		}

		else if (break_signal)
		{
			break;
		}
		s++;
	}

	if (sign < 0)
		total = total * -1;

	return (total);
}

