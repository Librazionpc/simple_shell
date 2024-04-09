#include <stdio.h>
#include <stdlib.h>

/**
 * multiples - Function that check for the multiples if 3 and
 *
 * Return: Always 0
 */

void multiples(void)
{
	int a, b;

	for (a = 0; a < 1024; a++)
	{
		if ((a % 3) == 0 || (a % 5) == 0)
		{
			b += a;
		}
	}
printf("%d\n", b);
}

/**
 * main - the function that call the multiple function
 *
 * Return: Always 0
 */
int main(void)
{
	multiples();
	return (0);
}

