#include "shell.h"

/**
 * execute_command_with_args - Execute a command with arguments
 * @command: The command to execute
 * @args: An array of argument strings
 *
 * Return: 0 on success, -1 on failure
 */

int execute_command_with_args(const char *command, char *const args[])
{
        int status;

        pid_t child_pid = fork();

        if (child_pid == -1)
        {
                perror("Error forking process");
                return (-1);
        }
        else if (child_pid == 0)
        {
                execve(command, args, NULL);
                perror("Error executing command");
                exit(EXIT_FAILURE);
        }
        else
        {
                waitpid(child_pid, &status, 0);
        }

        return (0);
}
