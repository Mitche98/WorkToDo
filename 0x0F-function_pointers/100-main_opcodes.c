#include <stdio.h>
#include <stdlib.h>
/**
 * print_opcodes - prints opscode of program
 * @a: address of main function
 * @n: number of bytes to print
 *
 * Return: void
 */
void print_opcodes(char *a, int n)
{
	int c;

	for (c = 0; c < n; c++)
	{
		printf("%.2hhx", a[c]);
		if (c < n - 1)
			printf(" ");
	}
	printf("\n");
}

/**
 * main - prints opcodes of main function
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: Always 0
 */
int main(int argc, char **argv)
{
	int f;

	if (argc != 2)
	{
		printf("Error\n");
		exit(1);
	}

	f = atoi(argv[1]);
	if (f < 0)
	{
		printf("Error\n");
		exit(2);
	}

	print_opcodes((char *)&main, f);
	return (0);
}
