#include <stdlib.h>
#include "function_pointers.h"

/**
 * print_name - Funtion that print a name
 *
 * @name: Fetches the string
 * @f: Calls the funtion
 *
 * Return: Nothing
 */

void print_name(char *name, void (*f)(char *))
{
	if (f == NULL || name == NULL)
		return;
	f(name);
}
