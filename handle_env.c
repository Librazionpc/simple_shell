#include "main.h"

/**
 *
 *
 *
 *
 *
 */

void handle_evnp(char *envp[])
{
	int i;

	for (i = 0; envp[i] != NULL; i++)
	{
		printf("%s\n", envp[i]);
		break;
	}
}

