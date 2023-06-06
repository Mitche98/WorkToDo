#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_buffer(char *file);
void close_file(int fd);

/**
 * create_buffer - allocates 1024 bytes for buffer
 * @file: name of file buffer is storing chars
 *
 * Return: pointer to newly-allocated buffer
 */
char *create_buffer(char *file)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);

	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO,
				"Error, Can't write to %s\n", file);
		exit(99);
	}

	return (buffer);
}

/**
 * close_file - closes file descriptors
 * @fd: file descriptor to be closed
 */
void close_file(int fd)
{
	int h;

	h = close(fd);

	if (h == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * main - copies content of file to another file
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	int job, is, t, d;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buffer = create_buffer(argv[2]);
	job = open(argv[1], O_RDONLY);
	t = read(job, buffer, 1024);
	is = open(argv[2], _CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (job == -1 || t == -1)
		{
			dprintf(STDERR_FILENO,
					"Error: Can't read from file %s\n",
					argv[1]);
			free(buffer);
			exit(98);
		}

		d = write(is, buffer, t);
		if (is == -1 || d == -1)
		{
			dprintf(STDERR_FILENO,
					"Error: Can't write to %s\n", argv[2]);
			free(buffer);
			exit(99);
		}

		t = read(job, buffer, 1024);
		is = open(argv[2], O_WRONLY | O_APPEND);
	} while (t > 0);

	free(buffer);
	close_file(job);
	close_file(is);

	return (0);
}
