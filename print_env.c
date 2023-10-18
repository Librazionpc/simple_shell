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
	char *env_val = NULL;
	char **hsh_vars = NULL;

	hsh_vars = envp_vars();
	if (hsh_vars != NULL)
	{
		for (i = 0; hsh_vars[i] != NULL; i++)
		{
			env_val = getenv(hsh_vars[i]);
			if (env_val != NULL)
				printf("%s=%s\n", hsh_vars[i], env_val);
		}
	}
	if (env_val == NULL)
	{
		for (i = 0; envp[i] != NULL; i++)
			printf("%s\n", envp[i]);
	}
	return 0;
}

