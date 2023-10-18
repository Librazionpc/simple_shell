#include "main.h"

char **envp_vars() 
{
	char **envp = NULL;
	int num_vars = 0, i, len = 0;
	char *env_vars[] = {"USER", "LANGUAGE", "USER",
	"SESSION", "COMPIZ_CONFIG_PROFILE", "SHLVL", "HOME",
	"C_IS", "DESKTOP_SESSION", "LOGNAME", "TERM", "PATH",
	"DISPLAY"
	};
	num_vars = sizeof(env_vars) / sizeof(env_vars[0]);
	envp = (char **)malloc((num_vars + 1) * sizeof(char *));
	if (envp == NULL)
		return NULL;

	for (i = 0; i < num_vars; i++)
	{
		len += strlen(env_vars[i]);
		envp[i] = strdup(env_vars[i]);
	}
	envp[i] = NULL;
	return (envp);
}

