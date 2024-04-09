#include <stdio.h>
#include "main.h"
/**
 * _strcat - A function that concatenate two strings
 *
 * @dest: Fetches the argument from the main.c
 * @src: Fetches the argumnet from the main.c
 *
 * Return: Print pt that the destination results
 */
char *_strcat(char *dest, char *src)
{
	char *pt = dest;

	while (*dest != '\0')
		dest++;

	while (*src != '\0')
		*dest++ = *src++;

	*dest = '\0';
	return (pt);
}
