int multipy(int number1, int number2);
#include <stdio.h>
#include "main.h"
#include <stdlib.h>

/**
 * multiply - Function that multiply two number
 *
 * @number1: Fetches the first the argument
 * @number2: Fetches the second the argument
 *
 * Return: The results to the main function
 */

int multiply(int number1, int number2)
{
	return (number1 * number2);
}

/**
 * main - Function that calls multiply
 *
 * @argc: Fetches how many arguments passed on the terminal
 * @argv: Fetches the arguments passed that is INT
 *
 * Return: Always (Success)
 */

int main(int argc, char *argv[])
{
	int a, b;

	if (argc < 3)
	{
		printf("Error\n");
		return (1);
	}

	a = atoi(argv[1]);
	b = atoi(argv[2]);
	printf("%d\n", multiply(a, b));
	return (0);
}
