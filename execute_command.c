#include "main.h"


/**
 * perform_args - Takes path from args_exist_in_path and user args
 * @evnp: a pointer to all environment variables
 * @path_needed: Fetches the exact path from args_exist_in_path
 * @args: Fecthes the args from string_manipulation
 *
 * Return: The exit_status
 */
int perform_args(char *path_needed, char **args, environment *evnp)
{
	pid_t child_pid;
	int execve_status = -1;
	int exit_status = 0, status;
	char **string_env;

	if (path_needed != NULL)
	{
		child_pid = fork();
		if (child_pid < 0)
		{
			return (execve_status);
		}
		if (child_pid == 0)
		{
			string_env = convert_list_to_string(evnp);
			execve_status = execve(path_needed, args, string_env);
			if (execve_status < 0)
				exit(2);
		}
		wait(&status);
		if (WIFEXITED(status))
			exit_status = WEXITSTATUS(status);
	}
	return (exit_status);
}
