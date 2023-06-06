#include <stdlib.h>
#include "main.h"
/**
 * *argstostr - concats all arguments of the program
 * @ac: number of arguments
 * @av: array of arguments
 *
 * Return: pointer to new string (success), NULL (error)
 */
char *argstostr(int ac, char **av)
{
	int r, t, i, die;
	char *str;

	if (ac == 0 || av == NULL)
		return (NULL);

	for (r = 0; r < ac; r++)
	{
		for (t = 0; av[r][t] != '\0'; t++)
			die++;
		die++;
	}

	str = malloc(sizeof(char) * (die + 1));

	if (str == NULL)
		return (NULL);

	i = 0;

	for (r = 0; r < ac; r++)
	{
		for (t = 0; av[r][t] != '\0'; t++)
		{
			str[i] = av[r][t];
			i++;
		}
		str[i] = '\n';
		i++;
	}

	return (str);
}


