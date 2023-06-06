#include "3-calc.h"
#include <stdlib.h>
#include <string.h>

/**
 * get_op_func - selects correct function to perform
 * @s: operator
 *
 * Return: pointer to corresponding function
 */
int (*get_op_func(char *s))(int, int)
{
	op_t ops[] = {
		{"+", op_add},
		{"-", op_sub},
		{"*", op_mul},
		{"/", op_div},
		{"%", op_mod},
		{NULL, NULL}
	};

	int t = 0;

	while (t < 5)
	{
		if (strcmp(s, ops[t].op) == 0)
			return (ops[t].f);

		t++;
	}

	return (0);
}
