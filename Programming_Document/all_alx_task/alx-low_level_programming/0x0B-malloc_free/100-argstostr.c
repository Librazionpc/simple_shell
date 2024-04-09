#include <stdlib.h>
#include "main.h"

/**
 * argstostr - A function that concatenates all arguments of your program
 * @ac: number of arguments
 * @av: array containing arguments
 * Return: A pointer to string that containing all arguments
 * or NULL if ac == 0, if av == NULL, or upon failure
 */
char *argstostr(int ac, char **av)
{
	char *pt_new_str;
	int len = 0, a = 0, b, c = 0;

	if (ac <= 0 || av == NULL)
		return (NULL);

	for (; a < ac; a++)
	{
		for (b = 0; av[a][b]; b++)
			len++;
		len++;
	}

	pt_new_str = malloc(sizeof(char) * len + 1);
	if (pt_new_str == NULL)
		return (NULL);

	for (a = 0; a < ac; a++)
	{
		for (b = 0; av[a][b]; b++)
		{
			pt_new_str[c] = av[a][b];
			c++;
		}
		pt_new_str[c] = '\n';
		c++;
	}
	return (pt_new_str);
}
