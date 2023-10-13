#include "main.h"

/**
 * print_env - print all the environment variables
 * @env: a pointer to all the environment variables
 *
 * Return: 0 on success
 */
int print_env(char **env)
{
	int i = 0;

	if (env == NULL || *env == NULL)
		return (0);
	while (env[i] != NULL)
	{
		_fprintf(STDOUT_FILENO, "%s\n", env[i]);
		i++;
	}
	return (0);
}
