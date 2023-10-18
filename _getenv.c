#include "main.h"

/**
 *
 *
 *
 *
 */
char *get_env(char *name)
{
	int i = 0, is_present = 0;
	char *env_var = NULL, *value = NULL;
	char **hsh_vars = NULL;

	hsh_vars = envp_vars();
	if (hsh_vars == NULL)
		return NULL;

	for (; hsh_vars[i] != NULL; i++)
	{
		if (strncmp(hsh_vars[i], name, strlen(name)) == 0)
		{
			if (strlen(hsh_vars[i]) == strlen(name))
			{
				is_present = 1;
				break;
			}
		}
	}
	free_2d_arrays(hsh_vars);
	if (is_present)
	{
		for (i = 0; __environ[i] != NULL; i++)
		{
			env_var = __environ[i];
			if (strncmp(env_var, name, strlen(name)) == 0)
			{
				if (env_var[strlen(name)] == '=')
				{
					value = strchr(env_var, '=');
					if (value != NULL)
						return (value + 1);
				}
			}
		}
	}
	return (NULL);
}

