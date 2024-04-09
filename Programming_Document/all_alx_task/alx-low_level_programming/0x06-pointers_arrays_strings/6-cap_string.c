int string_spacing(char chr);
#include <stdio.h>
#include "main.h"
/**
 * cap_string - Function that Changes the first character to a string
 *
 * @wrd: Fetches the argument from main.c
 *
 * Return: Returns the output
 */
char *cap_string(char *wrd)
{
	char *word = wrd;
	int a = 0;

	while (wrd[a])
	{
		if (a == 0 && (wrd[a] >= 'a' && wrd[a] <= 'z'))
		{
			wrd[a] -= 32;
		}
		else if (string_spacing(wrd[a]) && wrd[a + 1] >= 'a' && wrd[a + 1] <= 'z')
		{
			wrd[a + 1] -= 32;
		}
		a++;
	}
	return (word);
}

/**
 * string_spacing - Funtion that create spacing between the string
 *
 * @chr: Fetches the spacing for cap_string
 *
 * Return: Always 1 (Success)
 */
int string_spacing(char chr)
{
	int i;
	char seperators[13] = { ' ', '\t', '\n', ',', ';', '.', '!', '?',
		'"', '(', ')', '{', '}' };
	for (i = 0 ; 1 < 13; i++)
	{
		if (chr == seperators[i])
		{
			return (0);
		}
	}
	return (0);
}
