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
/**
 * struct ListOfPath - Linked list if the path
 * @directory: the paths
 * @next: the next node
 */

typedef struct ListOfPath
{
	char *directory;
	struct ListOfPath *next;
} ListOfPath;
int main(int argc, char *argv[], char *evnp[]);
char *prompt(int exit_status);
int shell_processor(char *command, char *progName, int no_runs, 
		char *envp[], int exit_status);
void removeLeadingSpaces(char *str);
char **string_manipulation(char *command);
char *menu(char **args, char *progName, int run, int exit_status);
void add_directory_to_list(ListOfPath **head, const char *directory);
void free_2d_arrays(char **args);
int free_linked_list(ListOfPath *path_needed);
ListOfPath *createLinkedListOfPath();
char **envp_vars();
int print_hsh_envp();
char *args_exist_in_path(ListOfPath *path_list, char **args);
int perform_args(char *path_needed, char **args, char *evnp[]);
#endif
