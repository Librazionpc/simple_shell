#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * _strlen - Function that calculate the lenght of a string
 *
 * @s: Fetches the string from the funtion
 *
 * Return: Returns the lenght
 */
int _strlen(char *s)
{
	int i, len;

	for (i = 0; *(s + i) != '\0'; i++)
		len++;
	return (len);
}
/**
 * _strdup - Function that returns a pointer to a newly allocated space
 * in memory, which contains a copy of the string given as a parameter.
 *
 * @str: Fetches the argument from main.c
 *
 * Return: The value in the allocated memory
 */
char *_strdup(char *str)
{
	int i, lenght;
	char *pt_string;

	if (str == NULL)
		return (NULL);
	lenght = _strlen(str);
	pt_string = (char *)malloc((sizeof(char) * lenght) + 1);
	if (pt_string == NULL)
		return (NULL);
	for (i = 0; i < lenght; i++)
	{
		pt_string[i] = *(str + i);
	}
	return (pt_string);
}
