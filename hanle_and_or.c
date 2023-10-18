#include "main.h"

/**
 * number_of_list - compute the number of entries
 * in a linked list
 * @head: the head of the linked list
 *
 * Return: the computed number
 */
int number_of_list(environment *head)
{
	int lenght_of_list = 0;

	while (head != NULL)
	{
		lenght_of_list++;
		head = head->next;
	}
	return (lenght_of_list);
}

/**
 * logical_args - run commands that are seperated by && and ||
 * @command: the command of the user
 * @prog_name: the name of the shell program
 * @no_runs: the number of times the shell program has run
 * @env: the head of the environment variables
 * @alias: the head of the alias linked list
 *
 * Return: the exit status
 */
int logical_args(char *command, char *prog_name, int no_runs,
		environment *env, environment **alias)
{
	char **and_operator, **or_operator;
	int exit_status = 0, i = 0, j = 0, or_pre;

	and_operator = split_to_string(command, '&');
	while (and_operator[i] != NULL)
	{
		or_pre = is_present(and_operator[i], "||");
		if (or_pre)
		{
			or_operator = split_to_string(and_operator[i], '|');
			while (or_operator[j] != NULL)
			{
				exit_status = execute_in_seq(or_operator[j], prog_name, no_runs,
						env, exit_status, alias);
				if (exit_status == 0)
					break;
				j++;
			}
			free_2d_arrays(or_operator);
		}
		else
		{
			exit_status = execute_in_seq(and_operator[i], prog_name, no_runs,
					env, exit_status, alias);
		}
		if (exit_status != 0)
			break;
		i++;
	}
	free_2d_arrays(and_operator);
	return (exit_status);
}
