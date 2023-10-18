#include "main.h"

/**
 * main - Calls the prompt function and pass the it return to shell_processor
 * @argv: The Argument passed form terminal
 * @argc: The Sum of parent arrays of argv from terminal
 * @evnp: the environment variable
 *
 * Return: Always 0
 */
int main(int argc, char *argv[], char *evnp[])
{
	char *cmd = NULL;
	environment *env_cmp, *alias = NULL;
	int program_runs = 0, exit_status = 0, log_and, log_or;

	env_cmp = init_env(evnp);
	if (argc == 1)
	{
		while (1)
		{
			cmd = prompt(env_cmp, alias);
			if (cmd != NULL)
				handle_comment(cmd);
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
				log_and = is_present(cmd, "&&");
				log_or = is_present(cmd, "||");
				if (log_and || log_or)
					exit_status = logical_args(cmd, argv[0], program_runs, env_cmp, &alias);
				else
					exit_status = execute_in_seq(cmd, argv[0], program_runs,
							env_cmp, exit_status, &alias);
				free(cmd);
				if (exit_status != 0)
					continue;
			}
		}
	}
	return (exit_status);
}
