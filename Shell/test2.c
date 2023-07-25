#include "test.h"

#define BUFFER_SIZE 1024

int main(void)
{
	char buff[BUFFER_SIZE];
	char *args[BUFFER_SIZE / 2 + 1];
	ssize_t run_it;
	int stat;

	while (1)
	{
		printf("Shell($) ");

		run_it = read(STDIN_FILENO, buff, BUFFER_SIZE);

		if (run_it == -1)
		{
			perror("read");
			exit(EXIT_FAILURE);
		}

		if (run_it == 0)
		{
			printf("\n");
			break;
		}

		buff[run_it - 1] = '\0';

		char *token;
		int arg_count = 0;

		token = strtok(buff, " ");
		while (token)
		{
			args[arg_count] = token;
			arg_count++;
			token = strtok(NULL, " ");
		}
		args[arg_count] = NULL;

		pid_t pid = fork();

		if (pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}

		if (pid == 0)
		{
			if (execvp(args[0], args) == -1)
			{
				perror("execvp");
				exit(EXIT_FAILURE);
			}
			exit(EXIT_SUCCESS);
		}
		else
		{
			waitpid(pid, &stat, 0);

			if (WIFEXITED(stat) && WEXITSTATUS(stat))
			{
				printf("Command not found.\n");
			}
		}
	}

	return (0);
}
