#include "main.h"
#include <stdarg.h>
#include <stdlib.h>

/**
 * uint_to_string_handler - Chooses unsigned int to string conversion function.
 * @format_specifier: Pointer to format specifier struct with length info.
 * @args: Variadic argument list containing the number to convert.
 *
 * Selects the correct unsigned integer conversion function based on
 * the length modifier in the format specifier.
 *
 * Return: Pointer to a newly allocated string representing the number.
 */
char *uint_to_string_handler(format_specifier_t *format_specifier,
							 va_list args)
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
