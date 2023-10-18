#ifndef _MAIN_H_
#define _MAIN_H_

#define MAX_COMMAND_SIZE 1024
#define MAX_ARGS_SIZE 128


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

typedef struct ListOfPath
{
	char *directory;
	struct ListOfPath *next;
} ListOfPath;

char *prompt(int exit_status, int fd);
ssize_t _getline(char **lineptr, size_t *n, int fd);
void removeLeadingSpaces(char *command);
void free_2d_arrays(char **args);
int free_linked_list(ListOfPath *path_needed);
int main(int argc, char *argv[], char *evnp[]);
int shell_processor(char *cmd, char *progName, int progRuns, char *evnp[], int exit);
char *menu(char **args, char *progName, int run, int exit);
ListOfPath *createLinkedListOfPath();
void add_directory_to_list(ListOfPath **head, const char *directory);
char **string_manipulation(char *command);
char *string_manipulation2(char *command);
char **get_env_evnp(char *envp[]);
char **envp_vars();
char *get_env(char *name);
int print_hsh_envp();
void add_vars_env(char ***envp, char *name);
int _setenv(char *name, char *value, int overwrite);
void change_directory(char **args, char *progName, int run);
char *args_exist_in_path(ListOfPath *path_list, char **args);
int perform_args(char *path_needed, char **args, char *evnp[]);
#endif
