#include "main.h"
#include <stdlib.h>

/**
 * char_handler - Converts a character from a va_list to a string.
 * @format_specifier: Pointer to format_specifier_t struct (unused here).
 * @args: A va_list containing the character to convert.
 *
 * Return: Pointer to a newly allocated string containing the character,
 *         or NULL if memory allocation fails.
 *
 * Note: The caller is responsible for freeing the returned string.
 */
char *char_to_string_handler(format_specifier_t *format_specifier,
							 va_list args)
{
	char c = va_arg(args, int);
	char *str;

	(void)format_specifier; /* unused */
	str = malloc(2);
	if (str == NULL)
		return (NULL);

	str[0] = c;
	str[1] = '\0';
	return (str);
}
