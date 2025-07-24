#include "main.h"
#include <stdarg.h>

/**
 * hexa_lower_to_string_handler - Dispatches lowercase hexadecimal conversion
 * based on length.
 * @format_specifier: Pointer to a format_specifier_t struct containing
 *                   formatting info, including length modifiers.
 * @args: va_list containing the value to convert to lowercase hexadecimal string.
 *
 * This function examines the length modifier in the format specifier and calls
 * the appropriate lowercase hexadecimal conversion function:
 *   - No modifier: calls hexa_lower_to_string_default
 *   - 'l': calls hexa_lower_to_string_l (or hexa_lower_to_string_ll if double 'l')
 *   - 'h': calls hexa_lower_to_string_h (or hexa_lower_to_string_hh if double 'h')
 *
 * Return: Pointer to a dynamically allocated string representing the lowercase
 *         hexadecimal value of the argument, or NULL on failure.
 *         The caller is responsible for freeing the returned string.
 */
char *hexa_lower_to_string_handler(format_specifier_t *format_specifier, va_list args)
{
	if (format_specifier->length[0] == '\0')
	{
		return (hexa_lower_to_string_default(args));
	}
	else if (format_specifier->length[0] == 'l')
	{
		return (hexa_lower_to_string_l(args));
	}
	else if (format_specifier->length[0] == 'h')
	{
		if (format_specifier->length[1] == 'h')
			return (hexa_lower_to_string_hh(args));
		return (hexa_lower_to_string_h(args));
	}

	return (hexa_lower_to_string_default(args));
}
