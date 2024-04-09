#include <stdio.h>
#include "main.h"
/**
 * string_toupper - Function that convert lowercase to uppercase
 *
 * @a: Fetches the argument from main.c
 *
 * Return: Returns the results
 */
char *string_toupper(char *a)
{
	char *word = a;

	while (*a != '\0')
	{
		if (*a >= 'a' && *a <= 'z')
		{
			*a -= 32;
		}
		a++;
	}
	return (word);
}
