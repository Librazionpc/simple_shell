#include <stdlib.h>
#include "main.h"

/**
 * argstostr - Function that concatenates all arguments of your program
 * from command line
 *
 * @ac: Fetches the number of arguments from command line
 * @av: Fetches the array containing arguments from the command line
 *
 * Return: A pointer to string that containing all arguments
 * or NULL if ac == 0, if av == NULL, or upon failure.
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
