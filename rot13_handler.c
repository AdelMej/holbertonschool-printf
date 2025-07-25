#include "main.h"
#include <stdarg.h>
#include <stdlib.h>

/**
 * rot13_string_handler - Applies ROT13 encoding to a string argument.
 * @fmt: Pointer to the format specifier struct (unused).
 * @args: va_list containing the string to encode.
 *
 * Return: A newly allocated ROT13-encoded string,
 *         or a copy of "(null)" if input is NULL.
 *
 * Description: This function duplicates the input string and applies
 * ROT13 encoding to all alphabetic characters. Non-alphabetic characters
 * remain unchanged. Caller is responsible for freeing the returned string.
 */
char *rot13_string_handler(format_specifier_t *fmt, va_list args)
{
	char *str = va_arg(args, char *);
	int size;
	unsigned int i;
	char *new_str;

	(void)fmt;
	if (str == NULL)
		return (_strdup("(null)"));

	size = _strlen(str);
	new_str = malloc(size + 1);
	if (new_str == NULL)
		return (NULL);

	for (i = 0; str[i] != '\0'; i++)
	{
		new_str[i] = str[i];
	}

	new_str[i] = '\0';
	for (i = 0; new_str[i] != '\0'; i++)
	{
		if (new_str[i] >= 'A' && new_str[i] <= 'Z')
			new_str[i] = (((new_str[i] - 'A') + 13) % 26) + 'A';
		else if (new_str[i] >= 'a' && new_str[i] <= 'z')
			new_str[i] = (((new_str[i] - 'a') + 13) % 26) + 'a';
	}

	return (new_str);
}
