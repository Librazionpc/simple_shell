#include "main.h"

/**
 *
 *
 *
 *
 *
 */

void add_vars_env(char ***envp, char *name)
{
	char **ptr_env = *envp, **new_env = NULL, *env_var = NULL;
	int i, num_vars = 0;

	while (ptr_env[num_vars] != NULL)
		num_vars++;

	new_env = (char **)malloc((num_vars + 2) * sizeof(char *));
	if (new_env == NULL)
	{
		perror("malloc");
		return;
	}
	
	for (i = 0; ptr_env[i] != NULL; i++)
	{
		new_env[i] = strdup(ptr_env[i]);
		if (new_env[i] == NULL)
		{
			free_2d_arrays(new_env);
			free_2d_arrays(ptr_env);
			return;
		}
	}

	env_var = (char *)malloc((strlen(name) + 2)* sizeof(char));
	if (env_var == NULL)
	{
		free_2d_arrays(ptr_env);
		free_2d_arrays(new_env);
		return;
	}
	snprintf(env_var, (strlen(name) + 2), "%s", name);
	new_env[i] = env_var;
	new_env[i + 1] = NULL;

	free_2d_arrays(ptr_env);
	*envp = new_env;
}


int _setenv(char *name, char *value, int overwrite)
{
	char *env_var = NULL, *new_env_var = NULL;
	char **hsh_vars = NULL;
	int env_size;
	hsh_vars = envp_vars();
	if (hsh_vars == NULL)
		return (1);
	env_var = get_env(name);
	if (env_var != NULL)
	{
		if (overwrite)
		{
			env_size = strlen(name) + strlen(value) + 2;
			new_env_var = malloc(env_size);
			if (new_env_var == NULL)
			{
				free_2d_arrays(hsh_vars);
			}
			add_vars_env(&hsh_vars, name);
			snprintf(new_env_var, env_size, "%s=%s", name, value);
			if(putenv(new_env_var) != 0)
			{
				free(new_env_var);
				free_2d_arrays(hsh_vars);
				printf("worng usage\n");
			}
		}
	}
	else
	{
		if (overwrite)
                {
                        env_size = strlen(name) + strlen(value) + 2;
                        new_env_var = malloc(env_size);
                        if (new_env_var == NULL)
                        {
                                free_2d_arrays(hsh_vars);
                        }
                        add_vars_env(&hsh_vars, name);        
                        snprintf(new_env_var, env_size, "%s=%s", name, value);
                        if(putenv(new_env_var) != 0)
                        {       
                                free(new_env_var);
                                free_2d_arrays(hsh_vars);
				printf("worng usage\n");
                        }
                }
	}
	return (0);
}
