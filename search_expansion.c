#include "main.h"

char *int_string(int);
/**
 * handle_expansion - replace $ sign with appropriate value
 * @argv: an array of strings
 * @exit_status: the exit status of the previous command
 *
 * Return: nothing
 */
void handle_expansion(char **argv, int exit_status, environment *env)
{
	int i = 0;
	pid_t pid;
	char *expansion;
	environment *node = NULL;

	while (argv[i] != NULL)
	{
		if (argv[i][0] == '$')
		{
			if (argv[i][1] == '$')
			{
				pid = getpid();
				expansion = int_string(pid);
				free(argv[i]);
				argv[i] = expansion;
			}
			else if (argv[i][1] == '?')
			{
				expansion = int_string(exit_status);
				free(argv[i]);
				argv[i] = expansion;
			}
			else if ((argv[i][1] != ' ' && argv[i][1] != '\0'))
			{
				node = search_env(env, argv[i] + 1, '\0');
				free(argv[i]);
				if (node != NULL)
				{
					expansion = node->variable;
					while (*expansion != '=')
						expansion++;
					argv[i] = strdup(expansion + 1);
				}
				else
				{
					expansion = (char *)malloc(sizeof(char) * 1);
					expansion[0] = '\0';
					argv[i] = expansion;
				}
			}
		}
		i++;
	}
}
/**
 * int_string - convert integer to string
 * @number: the number to convert
 *
 * Return: a string converted to
 */
char *int_string(pid_t number)
{
	pid_t mul = 1, lenght = 0, i = 0, is_negative = 0;
	char *string;

	if (number < 0)
	{
		is_negative = 1;
		number = number * -1;
		lenght++;
	}
	if (number >= 10)
	{
		while ((number / mul) >= 10)
		{
			mul *= 10;
			lenght++;
		}
		string = (char *)malloc(sizeof(char) * (lenght + 2));
		if (string == NULL)
			return (NULL);
		if (is_negative)
			string[i++] = '-';
		string[i++] = (number / mul) + '0';
		while (mul >= 10)
		{
			mul /= 10;
			string[i++] = ((number / mul) % 10) + '0';
		}
	}
	else
	{
		string = (char *)malloc(sizeof(char) * (lenght + 2));
		if (string == NULL)
			return (NULL);
		if (is_negative)
			string[i++] = '-';
		string[i++] = number + '0';
	}
	string[i]  = '\0';
	return (string);
}
