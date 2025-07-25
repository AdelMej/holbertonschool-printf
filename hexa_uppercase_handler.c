#include "main.h"
#include <stdarg.h>

/**
 * hexa_upper_to_string_handler - Dispatches uppercase hexadecimal conversion
 * based on length modifier in format specifier.
 * @format_specifier: Pointer to format_specifier_t struct containing
 *                   formatting info including length modifiers.
 * @args: va_list containing the value to convert to uppercase hex string.
 *
 * This function checks the length modifier in format_specifier and calls the
 * correct conversion function:
 *   - No modifier: hexa_upper_to_string_default
 *   - 'l': hexa_upper_to_string_l (or ll if double 'l')
 *   - 'h': hexa_upper_to_string_h (or hh if double 'h')
 *
 * Return: Pointer to dynamically allocated string representing the uppercase
 *         hexadecimal value of the argument, or NULL on failure.
 *         Caller is responsible for freeing the returned string.
 */
char *hexa_upper_to_string_handler(format_specifier_t *format_specifier,
								   va_list args)
{
	if (format_specifier->length[0] == '\0')
	{
		return (hexa_upper_to_string_default(args));
	}
	else if (format_specifier->length[0] == 'l')
	{
		return (hexa_upper_to_string_l(args));
	}
	else if (format_specifier->length[0] == 'h')
	{
		if (format_specifier->length[1] == 'h')
			return (hexa_upper_to_string_hh(args));
		return (hexa_upper_to_string_h(args));
	}

	return (hexa_upper_to_string_default(args));
}
