#include "main.h"

/**
 * main - Calls the prompt function and pass the it return to shell_processor
 * @argv: The Argument passed form terminal
 * @argc: The Sum of parent arrays of argv from terminal
 *
 * Return: Always 0
 */
int main(int argc, char *argv[], char *evnp[])
{
	char *cmd = NULL;
	environment *env_cmp;
	int program_runs = 0, exit_status = 0;

	env_cmp = init_env(evnp);
	if (argc == 1)
	{
		while (1)
		{
			cmd = prompt();
			program_runs++;
			if (isatty(0) == 0)
			{
				if (cmd == NULL)
					exit(exit_status);
			}
			if (cmd == NULL)
				continue;
			else
			{
				exit_status = shell_processor(cmd, argv[0], program_runs, env_cmp, exit_status);
				free(cmd);
				if (exit_status != 0)
					continue;
			}
		}
	}
	return (exit_status);
}
