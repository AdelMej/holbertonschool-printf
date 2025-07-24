#include "main.h"
#include <stdlib.h>
#include <stdarg.h>

/**
 * binary_to_string_handler - Dispatches binary conversion based on length.
 * @format_specifier: Pointer to the format_specifier_t struct containing
 *                    formatting info including length modifiers.
 * @args: va_list containing the value to convert to binary.
 *
 * This function checks the length modifier in the format specifier
 * and calls the appropriate binary conversion function:
 * - No modifier: uses binary_to_string_default
 * - 'l': uses binary_to_string_l
 * - 'll': uses binary_to_string_ll
 * - 'h': uses binary_to_string_h
 * - 'hh': uses binary_to_string_hh
 *
 * Return: Pointer to a dynamically allocated string containing the binary
 *         representation of the number, or NULL on failure.
 */
char *binary_to_string_handler(format_specifier_t *format_specifier, va_list args)
{
	if (format_specifier->length[0] == '\0')
	{
		return (binary_to_string_default(args));
	}
	else if (format_specifier->length[0] == 'l')
	{
		return (binary_to_string_l(args));
	}
	else if (format_specifier->length[0] == 'h')
	{
		if (format_specifier->length[1] == 'h')
			return (binary_to_string_hh(args));
		return (binary_to_string_h(args));
	}

	return (binary_to_string_default(args));
}
