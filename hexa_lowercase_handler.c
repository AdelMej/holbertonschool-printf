#include "main.h"
#include <stdarg.h>

/**
 * hexa_lower_to_string_handler - Handles lowercase hexadecimal conversion
 *                                based on length modifiers.
 * @format_specifier: Pointer to format_specifier_t struct
 *					  containing formatting information, including length modifiers.
 * @args: va_list containing the value to convert.
 *
 * Description: This function checks the length modifier in the format
 * specifier and dispatches the call to the appropriate
 * lowercase hexadecimal conversion
 *
 * function:
 *   - No modifier: calls hexa_lower_to_string_default
 *   - 'l': calls hexa_lower_to_string_l (or hexa_lower_to_string_ll if needed)
 *   - 'h': calls hexa_lower_to_string_h (or hexa_lower_to_string_hh)
 *
 * Return: Pointer to a dynamically allocated string representing the lowercase
 *         hexadecimal value, or NULL on failure. Caller must free the result.
 */
char *hexa_lower_to_string_handler(format_specifier_t *format_specifier,
								   va_list args)
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
