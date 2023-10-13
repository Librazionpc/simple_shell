#include "main.h"

environment *search_env(environment *env, char *variable)
{
	environment *node;
	int i;

	node = env;
	while (node != NULL)
	{
		for (i = 0; variable[i] != '='; i++)
		{
			if (node->variable[i] != variable[i])
				break;
		}
		if (node->variable[i] == '=')
			return (node);
		node = node->next;
	}
	return (NULL);
}

int set_env(environment *env, char *variable, char *value)
{
	environment *node;
	char *string;

	if (variable == NULL || value == NULL)
		return (2);
	string = concat_string(variable, value, '=');
	node = search_env(env, variable);
	if (node == NULL)
	{
		add_list_end(&env, string);
	}
	else
	{
		free(node->variable);
		node->variable = string;
	}
	return (0);
}
extern char **environ;
int main(void)
{
	environment *env_cmp, *node;

	env_cmp = init_env(environ);
	set_env(env_cmp, "PATH", "youaregood");
       set_env(env_cmp, "HABEEB", "wewantyou");	
	/*node = search_env(env_cmp, "PATH");*/
	print_list(env_cmp);
	return (0);
}
