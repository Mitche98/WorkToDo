#include "ptype.h"

#define MAX_LENGTH 100

int main()
{
	char command[MAX_LENGTH];
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
			execlp(command, command, NULL);

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
