#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include <string.h>

/**
 * str_concat - Function that concatenate two strings
 *
 * @s1: Fetches the argument first string
 * @s2: fetches the argument second string
 *
 * Return: The concatenated string
 */

char *str_concat(char *s1, char *s2)
{
	int  a = 0, i, len_a, len_b;
	char *pt_string;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	len_a = strlen(s1);
	len_b = strlen(s2);

	pt_string = (char *)malloc(sizeof(char) * (len_a + len_b + 1));

	if (pt_string == NULL)
		return (NULL);
	for (i = 0; i < len_a + len_b; i++)
	{
		pt_string[i] = *(s1 + i);
		if (i >= len_a)
		{
			pt_string[i] = *(s2 + a);
			a++;
		}

	}
	return (pt_string);
}
