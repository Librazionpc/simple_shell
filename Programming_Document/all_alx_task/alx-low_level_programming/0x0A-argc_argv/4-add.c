#include <stdio.h>
#include "main.h"
#include <stdlib.h>
#include <ctype.h>

/**
 * main - Function that print agrument passed in the command line
 *
 * @argc: Fetches how many arguments passed on the terminal
 * @argv: Fetches the arguments passed that is STRING
 *
 * Return: Always (Success)
 */

int main(int argc, char *argv[])
{	int num, sum = 0, a;

	while (argc > 1)
	{
		argc--;
		for (a = 0; argv[argc][a]; a++)
		{
			if (!(isdigit(argv[argc][a])))
			{
				printf("Error\n");
				return (1);
			}
		}
		num = atoi(argv[argc]);
		sum += num;
	}
	printf("%d\n", sum);
	return (0);
}
