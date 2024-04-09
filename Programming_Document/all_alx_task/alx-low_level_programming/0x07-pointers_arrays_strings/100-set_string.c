#include <stdio.h>
#include "main.h"

/**
 * set_string - Function that sets the value of a pointer to a char.
 * @s: Fetches the string the argument
 * @to: Fectes the second pointer
 */

void set_string(char **s, char *to)
{
	*s = to;
}
