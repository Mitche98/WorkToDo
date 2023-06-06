#include "main.h"
/**
 * append_text_to_file - appends text at end of file
 * @filename: pointer to name of file
 * @text_content: string to add to end of file
 *
 * Return: -1 if function fails, or file does not exist otherwise 1
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int g, r, eat = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (eat = 0; text_content[eat];)
			eat++;
	}

	g = open(filename, O_WRONLY | O_APPEND);
	r = write(g, text_content, eat);

	if (g == -1 || r == -1)
		return (-1);

	close(g);

	return (1);
}
