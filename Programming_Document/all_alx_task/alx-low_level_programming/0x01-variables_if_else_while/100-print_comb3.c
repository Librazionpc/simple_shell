#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int n;
	int b;

	for (n = 0; n <= 8; n++)
	{
		for (b = n + 1; b <= 9; b++)
		{
			if (n != b)
			{
				putchar(n + '0');
				putchar(b + '0');
				if (n == 8 && b == 9)
				{
					continue;
				}
				putchar(',');
				putchar(' ');
			}
		}
	}
	putchar('\n');
	return (0);
}
