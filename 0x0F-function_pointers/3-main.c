#include "function_pointers.h"
#include <stdlib.h>
#include <stdio.h>
#include "3-calc.h"

/**
 * main - prints result of simple operations
 * @argc: number or arguments
 * @argv: array of arguments
 *
 * Return: Always 0
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	int day1, day2;
	char *op;

	if (argc != 4)
	{
		printf("Error\n");
		exit(98);
	}

	day1 = atoi(argv[1]);
	op = argv[2];
	day2 = atoi(argv[3]);

	if (get_op_func(op) == NULL || op[1] != '\0')
	{
		printf("Error\n");
		exit(99);
	}

	if ((*op == '/' && day2 == 0) || (*op == '%' && day2 == 0))
	{
		printf("Error\n");
		exit(100);
	}

	printf("%d\n", get_op_func(op)(day1, day2));

	return (0);
}
