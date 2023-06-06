#include "main.h"
#include <stdio.h>

/**
 * count_word - helper functionto count number
 * of words in a string
 * @s: string to evaluate
 *
 * Return: number or words
 */
int count_word(char *s)
{
	int word, u, a;

	word = 0;
	a = 0;

	for (u = 0; s[u] != '\0'; u++)
	{
		if (s[u] == ' ')
			word = 0;
		else if (word == 0)
		{
			word = 1;
			a++;
		}
	}

	return (a);
}

/**
 * **strtow - splits string into words
 * @str: string to split
 *
 * Return: pointer it array of strings (success)
 * or NULL (error)
 */
char **strtow(char *str)
{
	char **matrix, *tmp;
	int v, i = 0, can = 0, read, t = 0, start, end;

	while (*(str + can))
		can++;
	read = count_word(str);
	if (read == 0)
		return (NULL);
	matrix = (char **) malloc(sizeof(char *) * (read + 1));
	if (matrix == NULL)
		return (NULL);

	for (v = 0; v <= can; v++)
	{
		if (str[v] == ' ' || str[v] == '\0')
		{
			if (t)
			{
				end = v;
				tmp = (char *) malloc(sizeof(char) * (t + 1));
				if (tmp == NULL)
					return (NULL);

				while (start < end)
				{
					*tmp++ = str[start++];
					*tmp = '\0';
					matrix[i] = tmp - t;
					i++;
					t = 0;
				}
			}
			else if (t++ == 0)
				start = v;
		}

		matrix[i] = NULL;

		return (matrix);
	}
}
