#include <stdio.h>
#include "main.h"
/**
 * _strcmp - Fuction that compare strings
 *
 * @s1: Fetches the first string
 * @s2: Fetches the second string
 *
 * Return: Returns the final the output
 */
int _strcmp(char *s1, char *s2)
{
	int a, b, ans = 15, len_a, len_b;
	char word_a, word_b;

	while (*s1 != '\0' && *s2 != '\0')
	{
		len_a++;
		len_b++;
		s1++;
		s2++;
	}
	for (a = 0; a < len_a; a++)
	{
		for (b = 0; b < len_b; b++)
		{
			word_a = s1[a];
			word_b = s2[a];
			if (word_a < word_b)
			{
				ans *= -1;
				return (ans);
			}
			else if (word_a > word_b)
			{
				return (ans);
			}
			else
			{
				return (0);
			}
		}
	}
	return (0);
}
