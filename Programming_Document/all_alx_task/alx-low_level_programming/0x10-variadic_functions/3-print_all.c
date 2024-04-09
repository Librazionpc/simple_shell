#include "variadic_functions.h"
#include <stdarg.h>
#include <ctype.h>

void print_all(const char * const format, ...)
{
	int i, a;
	char *word;

	va_list args;

	va_start(args, format);

	for (i = 0; format[i]; i++)
	{
		word = va_arg(args, char *);
		if (isdigit(word))
		{
			_putchar(*word);
			continue;
		}

		for (a = 0; word[i]; a++)
			_putchar(word[i]);
	}
	va_end(args);
}
