#include "main.h"

/**
 * init_env - initialize the environment variables
 * to linked list
 * @env: a pointer to the environment variable
 *
 * Return: the initialized environment variables
 */
environment *init_env(char **env)
{
	int i = 0;
	environment *head;

	head = NULL;
	if (env == NULL)
		return (NULL);
	while (env[i] != NULL)
	{
		add_list_end(&head, env[i]);
		i++;
	}
	return (head);
}

/**
 * add_list_end - add a new entry to the end of a linked list
 * @head: a pointer to the head of environment linked list
 * @string: the string to add
 *
 * Return: the head of the linked list
 */
environment *add_list_end(environment **head, char *string)
{
	environment *new_node, *tmp;

	new_node = (environment *)malloc(sizeof(environment) * 1);
	if (new_node == NULL)
		return (NULL);
	new_node->variable = strdup(string);
	new_node->next = NULL;
	if (*head == NULL)
	{
		*head = new_node;
	}
	else
	{
		tmp = *head;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new_node;
	}
	return (*head);
}

/**
 * print_list - print all the entries in the linked list
 * @head: the head of the linked list
 *
 * Return: 0 on sucess otherwise return 2
 */
int print_list(environment *head)
{
	environment *tmp;

	if (head == NULL)
		return (0);
	tmp = head;
	while (tmp != NULL)
	{
		printf("%s\n", tmp->variable);
		tmp = tmp->next;
	}
	return (0);
}

/**
 * free_list - free a linked list
 * @head: the head of the linked list
 *
 * Return: nothing
 */
void free_list(environment *head)
{
	environment *tmp, *pre_env;

	if (head == NULL)
		return;
	tmp = head;
	while (tmp != NULL)
	{
		pre_env = tmp;
		tmp = tmp->next;
		free(pre_env->variable);
		free(pre_env);
	}
}

/**
 * convert_list_to_string - convert linked list data structure to
 * array of strings
 * @head: the head of the linked list
 *
 * Return: the pointer to the array of strings
 */
char **convert_list_to_string(environment *head)
{
	char **strings;
	int no_of_nodes, i = 0;

	if (head == NULL)
		return (NULL);
	no_of_nodes = number_of_list(head);
	if (no_of_nodes == 0)
		return (NULL);
	strings = (char **)malloc(sizeof(char *) * (no_of_nodes + 1));
	if (strings == NULL)
		return (NULL);
	while (head != NULL)
	{
		strings[i] = head->variable;
		head = head->next;
		i++;
	}
	strings[i] = NULL;
	return (strings);
}
