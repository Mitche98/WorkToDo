#include "test.h"

#define BUFFER_SIZE 1024
#define MAX_ARGS 10

int checkCom(char *command)
{
	char *path = getenv("PATH");
	char *path_2 = strdup(path);
	char *dir = strtok(path_2, ":");

	while (dir)
	{
		char com_path[BUFFER_SIZE];
		snprintf(com_path, sizeof(com_path), "%s/%s", dir, command);

		if (access(com_path, X_OK) == 0)
		{
			free(path_2);
			return (1);
		}

		dir = strtok(NULL, ":");
	}

	free(path_2);
	return (0);
}

/**
 * parse - to parse command line arguments
 * @command: command to parse
 * @args: argument to be parsed
 *
 * Return: NULL
 */
void parse(char *command, char *args[])
{
	int argc = 0;
	char *take = strtok(command, " ");

	while (take != NULL && argc < MAX_ARGS)
	{
		args[argc] = take;
		take = strtok(NULL, " ");
		argc++;  
	}

	args[argc] = NULL;
}

/**
 * print_env - prints environment
 *
 * Return: void
 */
void print_env()
{
	extern char **environ;
	for (char **env = environ; *env != NULL; env++)
	{
		printf("%s\n", *env);
	}
}


int main(void)
{
	char command[BUFFER_SIZE];
	char *args[MAX_ARGS];
	char prompt[] = "Welcome Please Enter Command ($) ";

	while (1)
	{
		printf("%s", prompt);

		if (fgets(command, BUFFER_SIZE, stdin) == NULL)
		{
			printf("\nThank you, your shell session has ended....\n");
			break;
		}

		size_t tip = strlen(command);
		if (tip > 0 && command[tip - 1] == '\n')
		{
			command[tip - 1] = '\0';
		}

		parse(command, args);

		if (strcmp(args[0], "exit") == 0)
		{
			printf("Exiting your shell, goodbye....\n");
			break;
		}
		else if (strcmp(args[0], "back") == 0)
		{
			printf("Back to VAG\n");
			break;
		}

		else if (strcmp(args[0], "env") == 0)
		{
			print_env();
		}
		else if (checkCom(args[0]))
		{
			pid_t pid = fork();
			if (pid < 0)
			{
				perror("Fork error");
			}
			else if (pid == 0)
			{
				if (execvp(args[0], args) == -1)
				{
					perror("Error executing command");
					exit(EXIT_FAILURE);
				}
			}
			else
			{
				int act;
				waitpid(pid, &act, 0);

				if (WIFEXITED(act))
				{
					int exit_stat = WEXITSTATUS(act);
					if (exit_stat)
					{
						printf("Command returned non-exit status: %d\n", exit_stat);
					}
					else if (WIFSIGNALED(act))
					{
						int sig_num = WTERMSIG(act);
						printf("Command terminated by signal: %d\n", sig_num);
					}
				}
			}
		}
		else
		{
			printf("Command not found: %s\n", args[0]);
		}
		
	}
	return (0);
}
