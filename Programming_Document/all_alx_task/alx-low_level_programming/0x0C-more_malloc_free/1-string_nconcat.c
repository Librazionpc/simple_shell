#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * _strlen - Function that calculate of a string
 *
 * @s: Fetches the argument string
 *
 * Return: The length of the passed string
 */

int _strlen(char *s)
{
	int len = 0;

	while (*s)
	{
		len++;
		s++;
	}

	return (len);
}

/**
 * string_nconcat - Function that concatinate two string
 *
 * @s1: Fetches the first string argument
 * @s2: Fetches the second string argument
 * @n: Fetches the size of the byte
 *
 * Return: The concatinated string
 */

char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	int a, b = 0, len_a, final_lenght;
	unsigned int len_b;
	char *ptr_concat_string;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	len_a = _strlen(s1);
	len_b = _strlen(s2);

	if (n >= len_b)
		n = len_b;
	final_lenght = len_a + n;
	ptr_concat_string = malloc(sizeof(char) * final_lenght + 1);
	if (ptr_concat_string == NULL)
		return (NULL);
	for (a = 0; a < final_lenght; a++)
	{
		*(ptr_concat_string + a) = s1[a];
		if (a >= len_a && a < final_lenght)
		{
			*(ptr_concat_string + a) = s2[b];
		b += 1;
		}
	}
	ptr_concat_string[final_lenght] = '\0';
	return (ptr_concat_string);
}
