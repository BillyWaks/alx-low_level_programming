#include "shell.h"

/**
 * find_command_in_path - Search for a command in the directories listed in PATH
 * @command: The command to search for
 *
 * Return: The full path to the command if found, NULL if not found
 */

char *find_command_in_path(const char *command)
{
        char *path = getenv("PATH");
        char *path_copy;
        char *token;
        int path_len;
        int command_len;
        char *full_path;

        if (path == NULL)
        {
                perror("Error getting PATH");
                return (NULL);
        }

        path_copy = strdup(path);
        if (path_copy == NULL)
        {
                perror("Error duplicating PATH");
                return (NULL);
        }

        token = strtok(path_copy, ":");

        while (token != NULL)
        {
                path_len = strlen(token);
                command_len = strlen(command);

                full_path = (char *)malloc(path_len + command_len + 2); /* +2 for '/' and null terminator */

                if (full_path == NULL)
		{
                        perror("Error allocating memory");

                        free(path_copy);

                        return (NULL);
                }

                strcpy(full_path, token);
                full_path[path_len] = '/';
                strcpy(full_path + path_len + 1, command);

                if (access(full_path, X_OK) == 0)
                {
                        free(path_copy);

                        return (full_path);
                }

                free(full_path);

                token = strtok(NULL, ":");
        }

        free(path_copy);

        return (NULL);
}
