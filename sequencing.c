#include "main.h"

/**
 * execute_in_seq - run all the commands that a seperated by ;
 * @cmd: the command on the user
 * @prog_name: the name of the shell program
 * @no_runs: the number of times the shell program has run
 * @env: the head of the environment variables
 * @exit_status: the exit status of the previous command
 * @alias: the head of the alias linked list
 *
 * Return: the exit status
 */
int execute_in_seq(char *cmd, char *prog_name, int no_runs,
		environment *env, int exit_status, environment **alias)
{
	int i = 0, seq_pre;
	char **commands;

	seq_pre = is_present(cmd, ";");
	if (seq_pre)
	{
		commands = split_to_string(cmd, ';');
		if (commands == NULL)
			return (2);
		while (commands[i] != NULL)
		{
			exit_status = shell_processor(commands[i], prog_name, no_runs,
					env, exit_status, alias);
			i++;
		}
		free_2d_arrays(commands);
	}
	else
	{
		exit_status = shell_processor(cmd, prog_name, no_runs,
				env, exit_status, alias);
	}
	return (exit_status);
}
