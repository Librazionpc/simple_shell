#include "main.h"

/**
 * count_argv - compute the number of args
 * @argv: a pointer to the args
 *
 * Return: the number computed
 */
int count_argv(char **argv)
{
	int no_of_args = 0;

	while (*argv != NULL)
	{
		no_of_args++;
		argv++;
	}
	return (no_of_args);
}

/**
 * _exit - exit the program with an exit status
 * @argv: a pointerto the args
 * @exit_status: the exit_status to exit with
 * @env: the head of the environment variable
 * @alias: the head of the alias variable
 * @prog_name: the name of the shell program
 * @no_run: the number of times the shell program has run
 * @command: the initial command
 *
 * Return: nothing
 */
int _exit_prog(char **argv, int exit_status, environment *env,
		environment *alias, char *prog_name, int no_run, char *command)
{
	int no_of_args = 0;

	no_of_args = count_argv(argv);
	if (no_of_args == 1)
	{
		free(command);
		free_2d_arrays(argv);
		free_list(env);
		free_list(alias);
		exit(exit_status);
	}
	if (no_of_args == 2)
	{
		exit_status = _atoi(argv[1]);
		if (exit_status == -1)
		{
			_fprintf(STDERR_FILENO, "%s: %d: exit: Illegal number: %s\n",
				prog_name, no_run, argv[1]);
			return (2);
		}
		free(command);
		free_2d_arrays(argv);
		free_list(env);
		free_list(alias);
		exit(exit_status);
	}
	else
	{
		_fprintf(STDERR_FILENO, "Usage: exit exit_status");
		return(2);
	}
}

/**
* _atoi - convert  a string to number
* @value: a string of numbers
*
* Return: the integer format
*/
int _atoi(char *value)
{
	int number = 0;
	int i = 0, is_negative = 0;

	if (value == NULL)
		return (-1);
	if (value[i] == '-')
	{
		return (-1);
	}
	while (value[i] != '\0')
	{
		if (value[i] < '0' || value[i] > '9')
			return (-1);
		number = number * 10 + (value[i] - '0');
		i++;
	}
	if (is_negative)
		number *= -1;
	return (number);
}
