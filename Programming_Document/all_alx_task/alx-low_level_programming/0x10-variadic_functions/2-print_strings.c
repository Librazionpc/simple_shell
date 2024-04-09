#include <stdarg.h>
#include <stdio.h>
#include "variadic_functions.h"

/**
 * print_strings - Funtion that print strings
 *
 * @separator: Fetches the string that separate the strings
 * @n: Fetches the number of string passed has the argument
 *
 * Return: Nothing
 */

void print_strings(const char *separator, const unsigned int n, ...)
{
	unsigned int i;
	char *string;
	va_list args;

	va_start(args, n);

	for (i = 0; i < n; i++)
	{
		string = va_arg(args, char *);
		if (string == NULL)
			printf("(nil)");
		if (string != NULL)
			printf("%s", string);
		if (separator == NULL)
			continue;
		if (i < n - 1)
		{
			printf("%s", separator);
		}
	}
	printf("\n");
	va_end(args);
}
