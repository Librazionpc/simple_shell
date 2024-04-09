#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * argstostr- it concatinates all the arguments of your program
 *@ac: the number of the arguments
 *@av: a pointer to the array of the argument
 *
 *Return: a pointer to the concatinated string
 */

char *argstostr(int ac, char **av)
{
	int i, j, k;
	int lenght = 0;
	char *ptr;

	if (ac <= 0 || av == NULL)
	{
		return (NULL);
	}
	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j]; j++)
			lenght++;
		lenght++;
	}
	ptr = malloc(sizeof(char) * lenght + 1);
	if (ptr == NULL)
	{
		return (NULL);
	}
	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j]; j++)
		{
			ptr[k] = av[i][j];
			k++;
		}
		ptr[k] = '\n';
		k++;
	}
	return (ptr);
}
