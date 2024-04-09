#include <stdio.h>
#include "main.h"
#include <string.h>
/**
 * _strlen - Function that returns the length of a string.
 *
 * @s: Fetches the arguments from the main.c
 * Return: The lenght of the string.
 */
int _strlen(char *s)
{
	int i;
	int lenght = 0;

	for (i = 0; s[i] != '\0'; i++)
	{
		lenght += 1;
	}
	return (lenght);
}
