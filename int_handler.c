#include "main.h"
#include <stdlib.h>

/* Function declarations */
unsigned int _sizeofint(int number);

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
char *char_to_string_handler(format_specifier_t *format_specifier, va_list args)
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

/**
 * int_to_string_handler - Dispatches to the correct integer-to-string function
 *                 based on the length modifier in the format specifier.
 * @format_specifier: Pointer to the format specifier
 *					  struct containing length info
 * @args: va_list containing the integer argument to convert
 *
 * Return: Pointer to a newly allocated string
 *		   representing the formatted integer,
 *         or NULL if memory allocation fails
 *         or an unknown length modifier is used.
 *
 * Description: Handles standard length modifiers "", "l", "ll", "h", and "hh",
 * and calls the appropriate conversion function.
 * Falls back to default behavior
 * if no length modifier is present or unrecognized.
 */
char *int_to_string_handler(format_specifier_t *format_specifier, va_list args)
{
	if (format_specifier->length[0] == '\0')
	{
		return (int_to_string_default(args));
	}
	else if (format_specifier->length[0] == 'l')
	{
		return (int_to_string_l(args));
	}
	else if (format_specifier->length[0] == 'h')
	{
		if (format_specifier->length[1] == 'h')
			return (int_to_string_hh(args));
		return (int_to_string_h(args));
	}

	return (int_to_string_default(args));
}
