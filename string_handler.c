#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * string_handler - Copies a string argument from a va_list.
 * @format_specifier: Pointer to the format specifier struct (unused).
 * @args:            Variadic argument list containing the string to copy.
 *
 * Description:
 *   Retrieves a string argument from the variadic list. If the string is NULL,
 *   substitutes it with the string "(null)".
 *   Allocates memory for a copy of the
 *   string, copies it, and returns the newly allocated copy.
 *
 * Return: Pointer to the newly allocated string copy,
 * or NULL if memory allocation fails.
 */
char *string_handler(format_specifier_t *format_specifier, va_list args)
{
	char *str = va_arg(args, char *);
	char *cpy;
	unsigned int i, size;

	(void)format_specifier;

	if (str == NULL)
		str = "(null)";

	size = _strlen(str);
	cpy = malloc(size + 1);
	if (cpy == NULL)
		return (NULL);

	for (i = 0; i <= size; i++)
		cpy[i] = str[i];

	return (cpy);
}
