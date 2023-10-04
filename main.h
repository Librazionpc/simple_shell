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
int main(int argc, char *argv[]);
char *shell_processor(char *cmd, char *program_name, int no_program_runs);
char **string_manipulation(char *command);
void free_2d_arrays(char **args);
char *handle_path(void);
char *args_exist_in_path(char *path_buf, char **args, char *progName, int run);
int perform_args(char *path_needed, char **args);
#endif
