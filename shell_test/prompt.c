#include "shell.h"

/**
 * read_input - Read a line of input from the user
 *
 * Return: A dynamically allocated string containing user input
 */
char *read_input(void)
{
	char *user_input = NULL;
	size_t input_size = 0;
	ssize_t bytes_read;

	write(STDOUT_FILENO, "$ ", 2);
	bytes_read = getline(&user_input, &input_size, stdin);

	if (bytes_read == -1)
	{
		free(user_input);

		return (NULL);
	}

	if (user_input[bytes_read - 1] == '\n')
	{
		user_input[bytes_read - 1] = '\0';
	}

	return (user_input);
}

/**
 * command_exists - Check if a command exists in the "commands" file
 * @command: The command to check
 *
 * Return: 1 if the command exists, 0 otherwise
 */
int command_exists(const char *command)
{
	FILE *command_file = fopen("commands", "r");
	char line[256];
	int command_found;
	size_t len;

	if (command_file == NULL)
	{
		perror("Error opening command file");
		return (0);
	}

	command_found = 0;

	while (fgets(line, sizeof(line), command_file))
	{
		len = strlen(line);

		if (len > 0 && line[len - 1] == '\n')
		{
			line[len - 1] = '\0';
		}

		if (strcmp(command, line) == 0)
		{
			command_found = 1;
			break;
		}
	}

	fclose(command_file);
	return (command_found);
}

/**
 * main - Entry point for the shell program
 *
 * Return: Always 0
 */

int main(void)
{
	char *command;
	char *arg;

	while (1)
	{
		char *user_input = read_input();

		if (user_input == NULL)
		{
			break;
		}

		/* Split the user input into command and arguments */
		command = strtok(user_input, " ");
		arg = strtok(NULL, " ");
		/* Add more strtok calls if you expect more arguments */

		if (!command_exists(command))
		{
			write(STDOUT_FILENO, "No such file or directory\n", 26);
		}
		else
		{
			/* Create an array of arguments (including the command itself)*/
			char **args = malloc(3 * sizeof(char *));
			/* 3 elements: command, arg, and NULL*/

			if (args == NULL)
			{
				perror("Memory allocation failed");
				exit(EXIT_FAILURE);
			}

			args[0] = command;
			args[1] = arg;
			args[2] = NULL;

			execute_command_with_args(command, args);

			free(args); /* Don't forget to free the dynamically allocated memory */
		}
		free(user_input);
	}

	return (0);
}
