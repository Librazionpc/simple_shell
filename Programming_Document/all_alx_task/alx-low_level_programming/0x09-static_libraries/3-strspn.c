#include <stdio.h>
#include "main.h"
/**
 * _strspn - Function that gets the length of a prefix substring.
 *
 * @s: String to be searched for any match.
 * @accept: String that searches.
 *
 * Return: The amount of bytes or matches
 */
unsigned int _strspn(char *s, char *accept)
{
	int count = 0, flag;
	char *word = accept;

	while (*s)
	{
		flag = 0;
		while (*accept)
		{
			if (*accept == *s)
			{
				flag = 1;
				count++;
				break;
			}
			accept++;
		}
		s++;
		accept = word;
		if (flag == 0)
		{
			break;
		}
	}
	return (count);
}
