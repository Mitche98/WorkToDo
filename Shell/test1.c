#include "test.h"

#define BUFFER_SIZE 1024

int main(void)
{
	char buff[BUFFER_SIZE];
	ssize_t run_t;
	int stat;

	while (1)
	{
		printf("Shell*** ");

		run_t = read(STDIN_FILENO, buff, BUFFER_SIZE);

		if (run_t == -1)
		{
			perror("read");
			exit(EXIT_FAILURE);
		}

		if (run_t == 0)
		{
			printf("\n");
			break;
		}

		buff[run_t - 1] = '\0';

		pid_t pid = fork();

		if (pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}

		if (pid == 0)
		{
			if (execlp(buff, buff, NULL) == -1)
			{
				perror("execlp");
				exit(EXIT_FAILURE);
			}

			exit(EXIT_SUCCESS);
		}
		else
		{
			waitpid(pid, &stat, 0);

			if (WIFEXITED(stat) && WEXITSTATUS(stat) != 0)
			{
				printf("Command not found.\n");
			}
		}
	}

	return (0);
}
