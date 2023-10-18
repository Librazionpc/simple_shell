#include "main.h"

/**
 *
 *
 *
 *
 *
 */

int print_hsh_envp(char *envp[])
{
	int i;

	for (i = 0; envp[i] != NULL; i++)
	{
			printf("%s\n", envp[i]);
	}
	return (0);
}

