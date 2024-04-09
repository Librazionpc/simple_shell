#include <stdio.h>
#include <stdarg.h>

/**
 * print_numbers - Fuction that print numbers
 *
 * @separator: Fetches the spring seperate the integers
 * @n: Fetches the integers to be used
 *
 * Return: Nothing
 */

void print_numbers(const char *separator, const unsigned int n, ...)
{
	unsigned int i;
	int x;
	va_list args;

	va_start(args, n);

	for (i = 0; i < n; i++)
	{
		x = va_arg(args, unsigned int);
		printf("%d", x);

		if (separator == NULL)
			continue;
		if (i < n - 1)
			printf("%s", separator);
	}
	printf("\n");
	va_end(args);
}
