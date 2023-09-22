#ifndef SHELL_H
#define SHELL_H
#include <unistd.h>

extern char **environ;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stddef.h>
#include <sys/wait.h>

int execute_command_with_args(const char *command, char *const args[]);
int command_exists(const char *command);
char *find_command_in_path(const char *command);
void builtin_exit(void);

#endif
