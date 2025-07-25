#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * 
 * 
 * 
 * 
 * 
 * Return:
 */

char *reversed_string_handler(format_specifier_t *fmt, va_list args)
{
	char *reverse_string;
	char temp = 0;
	unsigned int index = 0;
	unsigned int length = 0;
	char *str = va_arg(args, char *);

	(void)fmt;
	length = _strlen(str);
	reverse_string = malloc(length + 1);

	if (reverse_string == NULL)
		return (NULL);

	for (index = 0; str[index] != '\0'; index++)
	{
		reverse_string[index] = str[index];
	}

	reverse_string[index] = '\0';

	for (index = 0; index < (length / 2) ; index++)
	{
		temp = reverse_string[index];
		reverse_string[index] = reverse_string[length - index - 1];
		reverse_string[length - index - 1] = temp;
	}
	return (reverse_string);
}
