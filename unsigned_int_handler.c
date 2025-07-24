#include "main.h"
#include <stdarg.h>
#include <stdlib.h>

/**
 * uint_to_string_handler - Selects and calls the correct function to convert
 *                          an unsigned integer to a string based on length modifiers.
 * @format_specifier: Pointer to a format_specifier_t struct with formatting details.
 * @args: A va_list containing the unsigned integer to convert.
 *
 * Return: Pointer to a newly allocated string representing the unsigned integer,
 *         or NULL if memory allocation fails.
 *
 * Description: Dispatches to the appropriate conversion function based on the
 *              length modifier ('', 'l', 'll', 'h', 'hh') found in the format specifier.
 *              The returned string must be freed by the caller.
 */
char *uint_to_string_handler(format_specifier_t *format_specifier, va_list args)
{
	if (format_specifier->length[0] == '\0')
	{
		return (uint_to_string_default(args));
	}
	else if (format_specifier->length[0] == 'l')
	{
		return (uint_to_string_l(args));
	}
	else if (format_specifier->length[0] == 'h')
	{
		if (format_specifier->length[1] == 'h')
			return (uint_to_string_hh(args));
		return (uint_to_string_h(args));
	}

	return (uint_to_string_default(args));
}
