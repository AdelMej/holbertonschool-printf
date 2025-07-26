#include "main.h"

/**
 * length_handler - Parses length modifiers from a format string.
 * @str: Pointer to the current position in the format string.
 * @format: Pointer to the format_specifier_t struct to store the result.
 *
 * Return: Pointer to the next character after length modifiers.
 *
 * Description: Handles standard length modifiers: 'h', 'hh', 'l', and 'll'.
 * Stores them in format->length as a null-terminated string.
 */
const char *length_handler(const char *str, format_specifier_t *format)
{
	if (*str == 'h')
	{
		format->length[0] = 'h';
		str++;
		if (*str == 'h')
		{
			format->length[1] = 'h';
			format->length[2] = '\0';
			str++;
			return (str);
		}
		format->length[1] = '\0';
		return (str);
	}
	else if (*str == 'l')
	{
		format->length[0] = 'l';
		str++;
		if (*str == 'l')
		{
			format->length[1] = 'l';
			format->length[2] = '\0';
			str++;
			return (str);
		}
		format->length[1] = '\0';
		return (str);
	}

	return (str); /* no length modifier */
}
