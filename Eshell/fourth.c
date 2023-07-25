#include "ptype.h"

#define MAX_LENGTH 100
#define MAX_ARGS 10

/**
 * parse - parses command and seperates command and arguments
 * @command: command line string
 * @args: array to store command and argument
 *
 * Return: number of arguments
 */
int parse(char *command, char **args)
{
	int arg_count = 0;
	char *token = strtok(command, " \t\n");

	while (token && arg_count < MAX_ARGS)
	{
		args[arg_count++] = token;
		token = strtok(NULL, " \t\n");
	}

	args[arg_count] = NULL;
	return (arg_count);
}

/**
 * checkCom - checks if command exists in any directories in PATH
 * @command: command to check
 *
 * Return: 1 if command exists, 0 otherwise
 */
int checkCom(char *command)
{
	char *path = getenv("PATH");
	char *dir = strtok(path, ":");

	while (dir)
	{
		char command_path[MAX_LENGTH];
		snprintf(command_path, sizeof(command_path), "%s/%s",
				dir, command);
		if (access(command_path, X_OK) == 0)
			return (1);
		dir = strtok(NULL, ":");
	}

	return (0);
}

/**
 * exitShell - Exits the shell
 */
void exitShell(void)
{
	printf("Shell is exiting...\n");
	exit(0);
}

/**
 * main - entry point
 *
 * Return: Always 0
 */
int main(void)
{
	char command[MAX_LENGTH];
	char *args[MAX_ARGS + 1];
	char prompt[] = "Shell ($) ";

	while (1)
	{
		printf("%s", prompt);

		if (fgets(command, sizeof(command), stdin) == NULL)
		{
			printf("\n");
			break;
		}

		command[strcspn(command, "\n")] = '\0';

		if (strcmp(command, "exit") == 0)
		{
			exitShell();
		}
		else if (checkCom(command))
		{
			pid_t pid = fork();

			if (pid < 0)
			{
				fprintf(stderr, "Error: Fork failed.\n");
				exit(1);
			}
			else if (pid == 0)
			{
				int arg_count = parse(command, args);
				execvp(args[0], args);

				fprintf(stderr, "Error: Execution failed.\n");
				exit(1);
			}
			else
			{
				wait(NULL);
			}
		}
		else
		{
			fprintf(stderr, "Error: Command not found.\n");
		}
	}

	return (0);
}
