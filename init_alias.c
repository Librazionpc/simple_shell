#include "main.h"

/**
 * check_alias - check if alias variable is present
 * @alias: the alias linked list to check from
 * @command: the string to check
 *
 * Return: nothing
 */
void check_alias(environment *alias, char **command)
{
	int i = 0, no_of_words = 0, k = 0;
	environment *node = search_env(alias, *command, '\0');
	char *new_command;

	if (node == NULL)
		return;
	while (node->variable[i] != '=')
		i++;
	/*move the pointer to the next character after =*/
	i++;
	/*move the pointer to the next character after '*/
	k = ++i;
	while (node->variable[i] != '\'')
	{
		/*run until it meet '*/
		no_of_words++;
		i++;
	}
	if (no_of_words == 0)
		return;
	new_command = (char *)malloc(sizeof(char) * (no_of_words + 1));
	if (new_command == NULL)
		return;
	i = 0;
	while (node->variable[k] != '\'')
	{
		/*run until it meet '*/
		new_command[i] = node->variable[k];
		k++;
		i++;
	}
	new_command[i] = '\0';
	free(*command);
	*command = new_command;
}
/**
 * is_present - check if a value is present in a string
 * @string: the string to check
 * @value: the value to check
 *
 * Return: 1 if found otherwise return 0
 */
int is_present(char *string, char *value)
{
	int i = 0, k = 0, j = 0;

	if (string == NULL || value == NULL)
	{
		return (0);
	}
	while (string[i] != '\0')
	{
		if (string[i] == value[j])
		{
			k = i;
			for (j = 0; value[j] != '\0'; j++)
			{
				if (string[k] != '\0')
				{
					if (string[k] != value[j])
						break;
				}
				else
					break;
			}
			if (value[j] == '\0')
				return (1);
		}
		i++;
	}
	return (0);
}
/**
 * add_apostrophe - put the value of an alias variable in a
 * single quotes
 * @string: the variable and value pair to add single quotes to
 * @alias: the head of the alias linked list
 *
 * Return: the new string
 */
char *add_apostrophe(char *string, environment *alias)
{
	int no_words = 0, i = 0, j, k = 0;
	char *variable, *value;

	while (string[i] != '=')
		i++;
	j = i;
	while (string[j++] != '\0')
		no_words++;
	value = (char *)malloc(sizeof(char) * (no_words + 1));
	j = i;
	while (string[++j] != '\0')
		value[k++] = string[j];
	value[k] = '\0';
	check_alias(alias, &value);
	no_words = strlen(value);
	variable = (char *)malloc(sizeof(char) * (i + no_words + 4));
	if (variable == NULL)
		return (NULL);
	i = 0;
	while (*string != '=')
	{
		variable[i++] = *string;
		string++;
	}
	variable[i++] = *string;
	variable[i++] = '\'';
	string++;
	j = 0;
	while (value[j] != '\0')
		variable[i++] = value[j++];
	variable[i++] = '\'';
	variable[i] = '\0';
	free(value);
	return (variable);
}
/**
 * add_alias - add a new alias variable to the
 * alias linked list
 * @alias: a pointer to the alias linked list
 * @value: the value to add
 *
 * Return: 0 on sucess otherwise return 2
 */
int add_alias(environment **alias, char *value)
{
	environment *node;
	char *new_string;

	if (value == NULL)
		return (2);
	node = search_env(*alias, value, '=');
	new_string = add_apostrophe(value, *alias);
	if (node == NULL)
	{
		add_list_end(alias, new_string);
		free(new_string);
	}
	else
	{
		free(node->variable);
		node->variable = new_string;
	}
	return (0);
}
/**
 * alias_function - this function is called when the
 * user command is alias
 * @argv: a pointer to the commands user inputed
 * @alias: a pointer to the head of the alias linked list
 *
 * Return: 0 on sucess otherwise return 2
 */
int alias_function(char **argv, environment **alias)
{
	int no_of_args, i = 1, present;
	environment *node;

	no_of_args = count_argv(argv);
	if (no_of_args == 1)
	{
		print_list(*alias);
		return (0);
	}
	while (argv[i] != NULL)
	{
		present = is_present(argv[i], "=");
		if (!present)
		{
			node = search_env(*alias, argv[i], '\0');
			if (node)
				_fprintf(STDOUT_FILENO, "%s\n", node->variable);
		}
		else
		{

			add_alias(alias, argv[i]);
		}
		i++;
	}
	return (0);
}
