#include "main.h"
#include <stdarg.h>
#include <stdlib.h>

/**
 * octal_to_string_handler - Dispatches octal conversion based on length.
 * @format_specifier: Pointer to the format_specifier_t struct containing
 *                    formatting info including length modifiers.
 * @args: va_list containing the value to convert to octal.
 *
 * This function checks the length modifier in the format specifier
 * and calls the appropriate octal conversion function:
 * - No modifier: uses octal_to_string_default
 * - 'l': uses octal_to_string_l
 * - 'll': uses octal_to_string_ll
 * - 'h': uses octal_to_string_h
 * - 'hh': uses octal_to_string_hh
 *
 * Return: Pointer to a dynamically allocated string containing the octal
 *         representation of the number, or NULL on failure.
 */
char *octal_to_string_handler(format_specifier_t *format_specifier,
							  va_list args)
{
	if (format_specifier->length[0] == '\0')
	{
		return (octal_to_string_default(args));
	}
	else if (format_specifier->length[0] == 'l')
	{
		return (octal_to_string_l(args));
	}
	else if (format_specifier->length[0] == 'h')
	{
		if (format_specifier->length[1] == 'h')
			return (octal_to_string_hh(args));
		return (octal_to_string_h(args));
	}

	return (octal_to_string_default(args));
}
