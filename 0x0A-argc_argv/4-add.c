#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/**
 * check_num - check digit in string
 * @str: array str
 *
 * Return: Always 0
 */
int check_num(char *str)
{
	unsigned int sort;

	sort = 0;
	while (sort < strlen(str))
	{
		if (!isdigit(str[sort]))
		{
			return (0);
		}

		sort++;
	}
	return (1);
}

/**
 * main - print name of program
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: Always 0
 */
int main(int argc, char *argv[])
{
	int sort;
	int str_to_int;
	int add = 0;

	sort = 1;
	while (sort < argc)
	{
		if (check_num(argv[sort]))
		{
			str_to_int = atoi(argv[sort]);
			add += str_to_int;
		}
		else
		{
			printf("Error\n");
			return (1);
		}

		sort++;
	}
	printf("%d\n", add);

	return (0);
}
