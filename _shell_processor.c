#include "main.h"

/**
 * run_command - run command using the execve function
 * @args: arrays of strings containing all the commands
 * @env: array of strings of the environment variables
 * @no_runs: the number of times the command has ran
 * @program_name: the name of the shell program
 *
 * Return: 0 on sucess otherwise return any other value
 */
int run_command(char **args, environment *env, int no_runs, char *program_name)
{
	int exit_status = 0;
	char *path_needed;

	path_needed = get_full_path(args[0]);
	if (path_needed != NULL)
	{
		if (access(path_needed, X_OK) == 0)
		{
			exit_status = perform_args(path_needed, args, env);
			free(path_needed);
			free_2d_arrays(args);
			return (exit_status);
		}
		else
		{
			perror("Error");
			free(path_needed);
			free_2d_arrays(args);
			return (130);
		}
	}
	_fprintf(STDERR_FILENO, "%s: %d: %s: not found\n",
			program_name, no_runs, args[0]);
	free_2d_arrays(args);
	return (127);
}
/**
 * shell_processor - Function that recieves the user input
 * and pass it accordingly calling each function at the expected time
 *
 * @command: The user input
 * @progName: The of the program that is running
 * @no_runs: Sum of the parent arrays of argv from main
 * @evnp: a pointer to all the environment variables
 * @exit_code: the value the previous command return with
 * @alias: a pointer to the head of the alias linked list
 *
 * Return: Null to the main funtion to cause continuation
 */
int shell_processor(char *command, char *progName, int no_runs,
	environment *evnp, int exit_code, environment **alias);
int shell_processor(char *command, char *progName, int no_runs,
		environment *evnp, int exit_code, environment **alias)
{
	char **args = NULL;
	int exit_status = 0;

	args  = split_to_string(command, ' ');
	if (args == NULL)
		return (exit_status);
	if (*args != NULL)
	{
		check_alias(*alias, &args[0]);
		if (strcmp(args[0], "exit") == 0)
		{
			exit_status = _exit_prog(args, exit_code, evnp,
					*alias, progName, no_runs, command);
		}
		else if (strcmp(args[0], "env") == 0)
		{
			exit_status = print_list(evnp);
			free_2d_arrays(args);
		}
		else if (strcmp(args[0], "cd") == 0)
		{
			change_directory(args, progName, no_runs);
			free_2d_arrays(args);
		}
		else if (strcmp(args[0], "setenv") == 0)
			exit_status = set_env(args, evnp, progName, no_runs);
		else if (strcmp(args[0], "unsetenv") == 0)
			exit_status = unset_env(evnp, args, progName, no_runs);
		else if (strcmp(args[0], "alias") == 0)
		{
			exit_status = alias_function(args, alias);
			free_2d_arrays(args);
		}
		else
		{
			exit_status = run_command(args, evnp, no_runs, progName);
			return (exit_status);
		}
	}
	return (exit_status);
}
