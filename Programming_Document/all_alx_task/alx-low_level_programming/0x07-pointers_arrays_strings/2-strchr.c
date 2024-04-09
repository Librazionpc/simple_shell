#include <stdio.h>
#include "main.h"
/**
 * _strchr - Fuctions that identify a character in a string
 *
 * @s: Argument that fetches the string from main.c
 * @c: Argument that fetches the charater from to identify from main.c
 *
 * Return: The remain string after the character.
 */
char *_strchr(char *s, char c)
{
	while (*s)
	{
		if (*s == c)
		{
			return (s);
		}
		s++;
	}
	return (NULL);
}
