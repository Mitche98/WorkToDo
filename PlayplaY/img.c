#include <stdio.h>
#include <unistd.h>

/**
 * check_betty - passes betty requirment
 * @argc: number of argument
 * @argv: array of arguments
 *
 * Return: Always 0
 */
int check_betty(int argc, char *argv[])
{
	int bet;
	void (argv[]);

	while (argc != 3)
	{
		for (bet = 0; argv[bet]; bet++)
		{
			if (bet >= 0)
			{
				printf("This is a remarkable feat\n");
				return (-1);
			}
			else
			{
				return (1);
			}
		}
		return (bet);
	}
	return (0);
}
