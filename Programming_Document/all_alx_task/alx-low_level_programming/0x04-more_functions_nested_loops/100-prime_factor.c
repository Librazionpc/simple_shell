#include <stdio.h>

/**
 * main - Entry point
 * Return: Always 0
 */
int main(void)
{
	unsigned long int a = 3, n = 612852475143;

	for (; a < 12050; a += 2)
	{
		while (n % a == 0 && n != a)
			n /= a;
	}
	printf("%lu\n", n);
	return (0);
}

