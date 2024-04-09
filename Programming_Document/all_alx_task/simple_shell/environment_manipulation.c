#include "main.h"

/**
 * search_env - check if an environment variable is present in
 * a linked list
 * @env: a pointer to the linked list to check
 * @variable: the variable to check
 * @dil: a delimeter that seperate the variable from value
 *
 * Return: the node if found otherwise return null
 */
environment *search_env(environment *env, char *variable, char dil)
{
	environment *node;
	int i;

	if (env == NULL)
		return (NULL);
	node = env;
	while (node != NULL)
	{
		for (i = 0; variable[i] != dil; i++)
		{
			if (node->variable[i] != variable[i])
				break;
		}
		if (node->variable[i] == '=' && (variable[i] == '\0' || variable[i] == dil))
			return (node);
		node = node->next;
	}
	return (NULL);
}

/**
 * add_env - add another entry to the environment linked list
 * @env: a pointer to the environment linked list
 * @variable: the variable value to add
 * @value: the value of the variable
 *
 * Return: 0 on sucess otherwise return 2
 */
int add_env(environment *env, char *variable, char *value)
{
	environment *node;
	char *string;

	if (variable == NULL || value == NULL)
		return (2);
	string = concat_string(variable, value, '=');
	node = search_env(env, variable, '=');
	if (node == NULL)
	{
		add_list_end(&env, string);
		free(string);
	}
	else
	{
		free(node->variable);
		node->variable = string;
	}
	return (0);
}

/**
 * set_env - set environment variable
 * @argv: a pointer to the argument vector
 * @env: a pointer to the environment linked list
 * @prog_name: the program name
 * @no_runs: the number of times commands as being ran
 *
 * Return: 0 on sucess otherwise return 2
 */
int set_env(char **argv, environment *env, char *prog_name, int no_runs)
{
	int no_of_args, exit_status;

	no_of_args = count_argv(argv);
	if (no_of_args == 3)
	{
		exit_status = add_env(env, argv[1], argv[2]);
		return (exit_status);
	}
	else
	{
		_fprintf(STDERR_FILENO, "%s: %d: Usage: setenv variable value\n",
				prog_name, no_runs);
	}
	return (2);
}
/**
 * remove_env - remove entry from the environment linked list
 * @env: a pointer to the head of the environment linked list
 * @variable: the entry to remove
 *
 * Return: 0 on sucess otherwise return non zero value
 */
int remove_env(environment **env, char *variable)
{
	environment *node, *pre_node;
	int i;

	if (variable == NULL)
		return (2);
	if (*env == NULL)
		return (2);
	node = *env;
	pre_node = *env;
	while (node != NULL)
	{
		for (i = 0; variable[i] != '='; i++)
		{
			if (node->variable[i] != variable[i])
				break;
		}
		if (node->variable[i] == '=')
		{
			if (node != pre_node)
			{
				pre_node->next = node->next;
			}
			else
				*env = node->next;
			free(node->variable);
			free(node);
			return (0);
		}
		pre_node = node;
		node = node->next;
	}
	return (2);
}
/**
 * unset_env - unset an environment variable
 * @env: the head of the environment variables
 * @argv: an array of commands
 * @program_name: the name of the shell program
 * @no_runs: the number of times commands has bein ran
 *
 * Return: 0 on sucess otherwise return non zero
 */
int unset_env(environment *env, char **argv, char *program_name, int no_runs)
{
	int no_of_args, exit_status;

	no_of_args = count_argv(argv);
	if (no_of_args == 2)
	{
		exit_status = remove_env(&env, argv[1]);
		return (exit_status);
	}
	else
	{
		_fprintf(STDERR_FILENO, "%s: %d: Usage: unsetenv variable\n",
				program_name, no_runs);
	}
	return (2);
}
