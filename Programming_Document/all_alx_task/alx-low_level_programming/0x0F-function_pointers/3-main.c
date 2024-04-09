#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "3-calc.h"
#include "function_pointers.h"

/**
 * main - Function that computer to integers
 *
 * @agrv: Fetches the string from command line
 * @argc: Fetches the amount of string passed from the command line
 *
 * Return: The conditions
 */

int main(int argc, char *agrv[])
{
	int results;
	int (*calc_cmd)(int, int);

	calc_cmd = get_op_func(agrv[2]);

	if (argc != 4)
	{
		printf("Error\n");
		return (98);
	}

	if (calc_cmd != NULL)
	{
		if ((!strcmp(agrv[2], "/") || !(strcmp(agrv[2], "%"))) && atoi(agrv[3]) == 0)
		{
			printf("Error\n");
			return (100);
		}
		results = calc_cmd(atoi(agrv[1]), atoi(agrv[3]));
		printf("%d\n", results);
	}
	else
	{
		printf("Error\n");
		return (99);
	}
	return (0);
}
