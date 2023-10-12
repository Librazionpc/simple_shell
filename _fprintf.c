#include "main.h"
#include <stdarg.h>

char *int_to_string(int n);
/**
 * _fprintf - print formated string to std file
 * @stream: the file stream to write to
 * @format: the string to write
 *
 * return: nothing
 */
void _fprintf(int stream, const char *string, ...)
{
	va_list args;
	int i = 0, k = 0;
	char buffer[250], *value;

	va_start(args, string);
	while (*string != '\0')
	{
		if (*string == '%')
		{
			string++;
			if (*string == 's')
			{
				value  = va_arg(args, char *);
				for (k = 0; value[k] != '\0'; k++)
				{
					buffer[i] = value[k];
					i++;
				}
			}
			else if (*string == 'd')
			{
				value = int_to_string(va_arg(args, int));
				for (k = 0; value[k] != '\0'; k++)
				{
					buffer[i] = value[k];
					i++;
				}

			}
		}
		else
		{
			buffer[i] = *string;
			i++;
		}
		string++;
	}
	free(value);
	va_end(args);
	buffer[i]  = '\0';
	write(stream, buffer, i);
}


char *int_to_string(int n)
{
	int mul = 1, lenght = 1, is_negative = 0, i = 0;
	char *string = NULL;
	if (n < 0)
	{
		lenght++;
		is_negative = 1;
		n = n * -1;
	}
	if (n >= 10)
	{
		while (n / mul > 10)
		{
			lenght++;
			mul *= 10;
		}
		string = (char *)malloc(sizeof(char) * lenght + 1);
		if (string == NULL)
			return (NULL);
		if (is_negative)
		{
			string[i] = '-';
			i++;
		}
		string[i] = (n / mul) + '0';
		i++;
		while (mul >= 10)
		{
			mul /= 10;
			string[i] = ((n / mul) % 10) + '0';
			i++;
		}
	}
	else
	{
		string = (char *)malloc(sizeof(char) * lenght + 1);
		if (is_negative)
		{
			string[i] = '-';
			i++;
		}
		string[i] = (n + '0');
		i++;
	}
	string[i] = '\0';
	return (string);
}
