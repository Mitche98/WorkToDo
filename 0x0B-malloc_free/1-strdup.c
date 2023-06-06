#include "main.h"
#include <stdlib.h>
/**
 * _strdup - copies string given as parameter
 * @str: string to duplicate
 *
 * Return: pointer to copied string
 */
char *_strdup(char *str)
{
	char *undilute;
	unsigned int h, fed;

	h = 0;
	fed = 0;

	if (str == NULL)
		return (NULL);

	while (str[fed])
		fed++;
	undilute = malloc(sizeof(char) * (fed + 1));

	if (undilute == NULL)
		return (NULL);

	while ((undilute[h] = str[h]) != '\0')
		h++;

	return (undilute);
}
