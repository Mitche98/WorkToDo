#include <stdio.h>
#include <stdarg.h>
#include "variadic_functions.h"

/**
 * print_all - prints all arguments when specified
 * @format: specifies necessary operation
 *
 * Return: void
 */
void print_all(const char * const format, ...)
{
	int c;
	int rig;
	char *buju;
	va_list bnxn;

	va_start(bnxn, format);
	c = 0;
	while (format != NULL && format[c] != '\0')
	{
		switch (format[c])
		{
			case 'c':
				printf("%c", va_arg(bnxn, int));
				rig = 0;
				break;
			case 'i':
				printf("%c", va_arg(bnxn, int));
				rig = 0;
				break;
			case 'f':
				printf("%c", va_arg(bnxn, int));
				rig = 0;
				break;
			case 's':
				buju = va_arg(bnxn, char *);

				if (buju == NULL)
					buju = "(nil)";
				printf("%s", buju);
				rig = 0;
				break;
			default:
				rig = 1;
				break;
		}
}
		if (format[c + 1] != '\0' && rig == 0)
			printf(", ");
		c++;

	}
	printf("\n");
	va_end(bnxn);
}
