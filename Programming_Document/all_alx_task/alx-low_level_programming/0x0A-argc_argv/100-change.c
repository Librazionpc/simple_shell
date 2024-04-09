#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "main.h"

/**
 * main - A program that prints the minimum number of coins to
 * make change for the remains of the money with the multiples of 5 from 25
 * @argc: Fetches the number of strings in argv
 * @argv: Fectes the strings in the command line
 *
 * Return: Always 1 (Success)
 */
int main(int argc, char **argv)
{
	int remains, coins = 0;

	if (argc == 2)
	{
		remains = atoi(argv[1]);
		if (remains < 0)
		{
			printf("%d\n", 0);
			return (0);
		}
		if (remains % 25 >= 0)
		{
			coins += remains / 25;
			remains = remains % 25;
		}
		if (remains % 10 >= 0)
		{
			coins += remains / 10;
			remains = remains % 10;
		}
		if (remains % 5 >= 0)
		{
			coins += remains / 5;
			remains = remains % 5;
		}
		if (remains % 2 >= 0)
		{
			coins += remains / 2;
			remains = remains % 2;
		}
		if (remains % 1 >= 0)
			coins += remains;
		printf("%d\n", coins);
		return (0);
	}
	else
	{
		printf("Error\n");
		return (1);
	}
}
