#include "main.h"

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

int print_list(environment *head)
{
	environment *tmp;

	if (head == NULL)
		return(0);
	tmp = head;
	while (tmp != NULL)
	{
		printf("%s\n", tmp->variable);
		tmp = tmp->next;
	}
	return (0);
}
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
