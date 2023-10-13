#ifndef _MAIN_H_
#define _MAIN_H_

#define MAX_COMMAND_SIZE 1024
#define MAX_ARGS_SIZE 128


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

typedef struct environment {
	char *variable;
	struct environment *next;
} environment;

environment *init_env(char **);
environment *add_list_end(environment **, char *);
int print_list(environment *);
int number_of_list(environment *);
void free_list(environment *);
char **convert_list_to_string(environment *);
char *prompt(void);
void removeLeadingSpaces(char *command);
int shell_processor(char *cmd, char *progName, int progRuns, environment *evnp, int exit_code);
void free_2d_arrays(char **args);
char *handle_path(void);
char *handle_evnp(char *argv[]);
int perform_args(char *path_needed, char **args,  environment *evnp);
char **split_to_string(char *string, char dil);
char *get_full_path(char *command);
void _fprintf(int, const char *, ...);
int print_env(char **env);
char *int_to_string(int n);
int _atoi(char *string);
int _exit_prog(char **argv, int exit_status, environment *env, char *prog_name,
		int no_runs, char *command);
char *concat_string(char *first, char *second, char dil);
#endif
