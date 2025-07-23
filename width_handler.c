#include "main.h"
#include <stdarg.h>

/* Function declarations */
int _isdigit (char c);

/**
 * width_handler - Parses width and precision from format string
 * @str: Pointer to the format substring starting at width/precision
 * @format: Pointer to the format_specifier_t struct to update
 * @args: Pointer to the va_list for handling '*' width/precision
 *
 * Description: Parses numeric width and precision values or '*' to
 * obtain them from the variadic arguments, updating the format struct.
 *
 * Return: Pointer to the next character in the format string after
 * parsing width and precision.
 */
const char *width_handler(const char *str, format_specifier_t *format, va_list *args)
{
	if (*str == '*') /* Width specified by argument */
	{
		format->width = va_arg(*args, int);
		str++;
	}

	/* Parse numeric width */
	while (*str != '\0' && _isdigit(*str))
	{
		format->width = format->width * 10 + (*str - '0');
		str++;
	}

	if (*str == '.') /* Precision specified */
	{
		str++; /* Skip '.' */
		if (*str == '*') /* Precision specified by argument */
		{
			format->precision = va_arg(*args, int);
			str++;
		}

		/* Parse numeric precision */
		while (*str != '\0' && _isdigit(*str))
		{
			format->precision = format->precision * 10 + (*str - '0');
			str++;
		}
	}

	return (str); /* Return position after width/precision */
}

/**
 * _isdigit - Checks if a character is a digit (0-9)
 * @c: The character to check
 *
 * Return: 1 if @c is a digit, 0 otherwise
 */
int _isdigit (char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}
