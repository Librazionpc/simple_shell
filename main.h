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
environment *search_env(environment *env, char *variable, char dil);
int print_list(environment *);
int number_of_list(environment *);
void free_list(environment *);
char **convert_list_to_string(environment *);
char *prompt(void);
void removeLeadingSpaces(char *command);
int shell_processor(char *cmd, char *progName, int progRuns, environment *evnp, int exit_code, environment **alias);
void free_2d_arrays(char **args);
char *handle_path(void);
char *handle_evnp(char *argv[]);
int perform_args(char *path_needed, char **args,  environment *evnp);
int lenght_of_word(char *string, char dil);
char *copy_word_to_buffer(char *string, int lenght, char dil);
char **split_to_string(char *string, char dil);
char *get_full_path(char *command);
void _fprintf(int, const char *, ...);
int print_env(char **env);
char *int_to_string(int n);
int _atoi(char *string);
int _exit_prog(char **argv, int exit_status, environment *env, environment *alias, char *prog_name,
		int no_runs, char *command);
char *concat_string(char *first, char *second, char dil);
int count_argv(char **argv);
int set_env(char **argv, environment *env, char *prog_name, int no_runs);
int unset_env(environment *env, char **argv, char *prog_name, int no_runs);
int alias_function(char **argv, environment **alias);
void check_alias(environment *alias, char **command);
environment **init_alias();
int logical_args(char *, char *, int, environment *, environment **);
int is_present(char *, char *);
int execute_in_seq(char *, char *, int, environment *, int, environment **);
void handle_comment(char *);
void handle_expansion(char **, int, environment *);
int number_of_list(environment *head);
#endif
