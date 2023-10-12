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

char *prompt(void);
void removeLeadingSpaces(char *command);
int shell_processor(char *cmd, char *progName, int progRuns, char *evnp[], int exit_code);
char **string_manipulation(char *command);
char *string_manipulation2(char *command);
void free_2d_arrays(char **args);
char *handle_path(void);
char *handle_evnp(char *argv[]);
char *args_exist_in_path(char *path_buf, char **args, char *progName, int run);
int perform_args(char *path_needed, char **args, char *evnp[]);
char **split_to_string(char *string, char dil);
char *get_full_path(char *command);
void _fprintf(int, const char *, ...);
int print_env(char **env);

#endif
