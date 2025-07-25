#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * reversed_string_handler - Returns a newly allocated reversed copy
 *                            of the input string.
 * @fmt: Pointer to format_specifier_t struct (unused).
 * @args: va_list containing the input string to reverse.
 *
 * Return: Pointer to a new string that is the reverse of the input string,
 *         or NULL if memory allocation fails.
 *
 * Description: If the input string is NULL, returns a duplicate of "(null)".
 * The caller is responsible for freeing the returned string.
 */
char *reversed_string_handler(format_specifier_t *fmt, va_list args)
{
	char *reverse_string;
	char temp = 0;
	unsigned int index = 0;
	unsigned int length = 0;
	char *str = va_arg(args, char *);

	printf("[DEBUG] reversed_string_handler received pointer: %p\n", (void *)str);
	if (str)
		printf("[DEBUG] string value: '%s'\n", str);
	else
		printf("[DEBUG] string is NULL\n");
	(void)fmt;

	if (str == NULL)
		return (_strdup("(null)"));

	length = _strlen(str);
	reverse_string = malloc(length + 1);
	if (reverse_string == NULL)
	{
		return (NULL);
	}

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
