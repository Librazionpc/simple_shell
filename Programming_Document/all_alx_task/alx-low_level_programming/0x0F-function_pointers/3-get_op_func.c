#include <stdio.h>
#include "3-calc.h"
#include <string.h>

/**
 * get_op_func - Function that checks the operation
 *
 * @s: Fetches the operation
 *
 * Return: The operation
 */

int (*get_op_func(char *s))(int, int)
{
	op_t ops[] = {
	{"+", op_add},
	{"-", op_sub},
	{"*", op_mul},
	{"/", op_div},
	{"%", op_mod},
	{NULL, NULL}
	};

	int a = 0;

	while (a < 5)
	{
		if (!strcmp(ops[a].op, s))
			return (ops[a].f);
		a++;
	}
	return (NULL);
}

