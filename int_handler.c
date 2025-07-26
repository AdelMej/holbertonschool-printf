#include "main.h"
#include <stdlib.h>

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
