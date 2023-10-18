#include "main.h"

/**
 *
 *
 *
 *
 *
 */
int print_hsh_envp()
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
	return 0;
}
