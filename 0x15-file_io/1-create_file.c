#include "main.h"

/**
 * create_file - creates file
 * @filename: pointer to name of file to create
 * @text_content: pointer to string to write to file
 *
 * Return: -1 if function fails, otherwise 1
 */
int create_file(const char *filename, char *text_content)
{
	int p, r, can = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (can = 0; text_content[can];)
			can++;
	}

	p = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	r = write(p, text_content, can);

	if (p == -1 || r == -1)
		return (-1);

	close(p);

	return (1);
}
