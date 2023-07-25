#include "ptype.h"

#define MAX_LENGTH 100
#define MAX_ARGS 10

/*
 * parse - parses command line and seperates commands & arguments
 * @command: command line string
 * @args: array to store command and arguments
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
	return arg_count;
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
	char prompt[] = "Shell($) ";

	while (1)
	{
		printf("%s", prompt);

		if (fgets(command, sizeof(command), stdin) == NULL)
		{
			printf("\n");
			break;
		}

		command[strcspn(command, "\n")] = '\0';

		int pid = fork();

		if (pid < 0)
		{
			fprintf(stderr, "Error: Fork failed.\n");
			exit(1);
		}
		else if (pid == 0)
		{
			int arg_count = parse(command, args);
			execvp(args[0], args);

			fprintf(stderr, "Error: Command not found.\n");
			exit(1);
		}
		else
		{
			wait(NULL);
		}
	}

	return (0);
}
