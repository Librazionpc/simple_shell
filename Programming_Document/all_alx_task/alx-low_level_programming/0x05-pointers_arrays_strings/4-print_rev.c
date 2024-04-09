#include <stdio.h>
#include "main.h"
#include <string.h>
/**
 * _strlen - Function that returns the length of a string.
 *
 * @str: Fetches the arguments from the main.c
 * Return: The lenght of the string.
 */
int _strlen(char *str)
{
	int a;
	int lenght = 0;

	for (a = 0; str[a] != '\0'; a++)
	{
		lenght += 1;
	}
	return (lenght);
}
/**
 * print_rev - Function that prints a string, in reverse,
 * followed by a new line
 * @s: Fetches the argument
 */
void print_rev(char *s)
{
	int a, num;

	num = _strlen(s);
	for (a = num - 1; a >= 0; a--)
	{
		putchar(s[a]);
	}
putchar('\n');
}
