#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main -Entry point
 *
 * Return: Always 0 (Success)
 */

int main(void)
{
	int n;
	int b;
	int a;

	for (n = 0; n <= 7; n++)
	{
		for (b = n + 1; b <= 8; b++)
		{
			for (a = b + 1; a <= 9; a++)
			{
				if (n != b && b != a)
				{
					putchar(n + '0');
					putchar(b + '0');
					putchar(a + '0');
					if (n == 7 && b == 8 && a == 9)
					{
						continue;
					}
					putchar(',');
					putchar(' ');
				}
			}
		}
	}
putchar('\n');
return (0);
}
