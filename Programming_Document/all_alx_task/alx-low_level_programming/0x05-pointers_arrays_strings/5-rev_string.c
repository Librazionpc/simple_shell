#include <stdio.h>
#include "main.h"
/**
 * rev_string - Function that reverses a string.
 *
 * @s: Fetches the argument
 */
void rev_string(char *s)
{
	int len = 0, a = 0;
	char word;

	while (s[len] != '\0')
		len++;

	while (a < len--)
	{
		word = s[a];
		s[a++] = s[len];
		s[len] = word;
	}
}
