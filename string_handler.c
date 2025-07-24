#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * string_cpy - Copies a string from a va_list to a newly allocated string.
 * @args: A va_list containing the string to copy.
 *
 * Return: Pointer to a newly allocated string copy,
 *         or NULL if memory allocation fails.
 *
 * Note: If the input string is NULL, "(null)" is copied instead.
 *       The caller is responsible for freeing the returned string.
 */
char *string_cpy(format_specifier_t *format_specifier, va_list args)
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
