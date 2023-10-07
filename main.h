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

char *prompt(void);
void removeLeadingSpaces(char *command);
int main(int argc, char *argv[], char *evnp[]);
int shell_processor(char *cmd, char *progName, int progRuns, char *evnp[]);
char **string_manipulation(char *command);
char *string_manipulation2(char *command);
void free_2d_arrays(char **args);
char *handle_path(void);
void handle_evnp(char *argv[]);
char *args_exist_in_path(char *path_buf, char **args, char *progName, int run);
int perform_args(char *path_needed, char **args, char *evnp[]);
#endif
