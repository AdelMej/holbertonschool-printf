#include "main.h"
#include "_string.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

/* Function declarations */
unsigned int _strlen(char *str);

/**
 * _printf - Mimics the standard printf function
 * @format: A format string containing zero or more format specifiers
 *
 * Description: Iterates over the format string, printing characters directly
 * or calling the appropriate function to handle format specifiers. Supports
 * dynamic memory allocation for formatting, which is properly freed after use.
 *
 * Return: The total number of characters printed, or -1 on error
 */
int _printf(const char *format, ...)
{
	unsigned int index, i, length = 0;
	char *res;
	va_list args;

	if (format == NULL)
		return (-1); /* Error string is null */

	if (format[0] == '\0')
		return (0);

	va_start(args, format);
	for (index = 0; format[index] != '\0'; index++)
	{
		if (format[index] == '%')
		{
			if (format[index + 1] == '\0')
			{
				va_end(args);
				return (-1); /* error incorrect parsing */
			}
			res = format_handler(format[index + 1], args);
			if (res == NULL)
			{
				va_end(args);
				return (-1); /* failed parsing or failed malloc */
			}
			length += _strlen(res);
			for (i = 0; res[i] != '\0'; i++)
				_putchar(res[i]);

			free(res);
			res = NULL;
			index++; /* skip next character */
		}
		else
		{
			_putchar(format[index]);
			length++;
		}
	}
	_putchar_flush();
	va_end(args);
	return (length);
}

/**
 * format_handler - Selects the appropriate print function for a specifier.
 * @specifier: The format specifier character.
 * @args: A va_list containing the arguments to format.
 *
 * Return: Pointer to a newly allocated string representing
 * the formatted output, or NULL if memory allocation fails
 * or an error occurs.
 */
char *format_handler(char specifier, va_list args)
{
	print_func_t function;
	char *str;

	if (specifier == '%') /* printing literal '%' */
	{
		str = malloc(2);
		if (str == NULL)
			return (NULL);

		str[0] = '%';
		str[1] = '\0';
		return (str);
	}

	/* getting the correct function for the specifier */
	function = get_print_function(specifier);
	if (function == NULL) /* skipping unknown specifier */
	{
		str = malloc(3);
		if (str == NULL)
			return (NULL);

		str[0] = '%';
		str[1] = specifier;
		str[2] = '\0';
		return (str);
	}

	return (function(args));
}
