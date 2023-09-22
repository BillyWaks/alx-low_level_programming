#include "shell.h"

int execute_command(const char *command, char *const args[])
{
        /* Get the PATH environment variable */
        char *path = getenv("PATH");
        char *token;
        char command_path[256];
        char error_msg[] = "Command not found: ";

        if (path == NULL)
        {
                perror("getenv");

                return (-1);
        }

        /* Tokenize the PATH variable to search for the command */
        token = strtok(path, ":");

        while (token != NULL)
        {
                strcpy(command_path, token);
                strcat(command_path, "/");
                strcat(command_path, command);

                /* Try to execute the command with execve */
                if (access(command_path, X_OK) == 0)
                {
                        if (execve(command_path, args, NULL) == -1)
                        {
                                perror("execve");
                                return (-1);
                        }
                }

                token = strtok(NULL, ":");
        }

        /* Command not found in any of the PATH directories */

        strcpy(error_msg, "Command not found: ");
        strcat(error_msg, command);
        strcat(error_msg, "\n");
        write(STDERR_FILENO, error_msg, strlen(error_msg));

        return (-1);
}
