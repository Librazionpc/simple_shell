#include <stdio.h>
#include "main.h"

/**
 * main - Function that print how many agrument passed in the command line
 *
 * @argc: Fetches how many arguments passed on the terminal
 * @argv: Fetches the arguments passed that is STRING
 *
 * Return: Always (Success)
 */

int main(int argc, char *argv[])
{
	if (*argv)
		printf("%d\n", argc - 1);
	return (0);
}
