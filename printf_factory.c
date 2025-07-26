#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

/* Function declarations */
unsigned int _strlen(char *str);
void init_format_info(format_specifier_t *info);

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
	unsigned int i, length = 0;
	char *res;
	format_specifier_t specifiers_format;
	va_list args;
	const char *ptr;

	init_format_info(&specifiers_format);
	if (format == NULL)
		return (-1); /* Error string is null */

	if (format[0] == '\0')
		return (0);

	va_start(args, format);
	for (ptr = format; *ptr != '\0'; ptr++)
	{
		if (*ptr == '%')
		{
			ptr++;
			if (*ptr == '\0')
			{
				va_end(args);
				return (-1); /* error incorrect parsing */
			}
			init_format_info(&specifiers_format);

			ptr = flag_handler(ptr, &specifiers_format);
			ptr = width_handler(ptr, &specifiers_format, &args);
			ptr = length_handler(ptr, &specifiers_format);
			specifiers_format.specifier = *ptr;
			res = format_handler(&specifiers_format, args);
			res = apply_all(&specifiers_format, res);
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
		}
		else
		{
			_putchar(*ptr);
			length++;
		}
	}
	_putchar_flush();
	va_end(args);
	return (length);
}

/**
 * format_handler - Selects the appropriate print function for a specifier.
 * @specifiers_format: Pointer to the format_specifier_t struct containing
 *                    the parsed format specifier and modifiers.
 * @args:             A va_list of the arguments to format.
 *
 * Return: Pointer to a newly allocated string containing the formatted output,
 *         or NULL if memory allocation fails or an error occurs.
 *
 * Description: Checks the specifier in specifiers_format. If it is '%',
 *              returns a string with a single '%'. If the specifier is
 *              unknown, returns a string with '%' followed by that unknown
 *              specifier. Otherwise, calls the matching print function
 *              with the given arguments and returns its output.
 */
char *format_handler(format_specifier_t *specifiers_format, va_list args)
{
	handler_func_t function;
	char specifier = specifiers_format->specifier;
	char *str;

	if (specifiers_format->specifier == '%') /* printing literal '%' */
	{
		str = malloc(2);
		if (str == NULL)
			return (NULL);

		str[0] = '%';
		str[1] = '\0';
		return (str);
	}

	/* getting the correct function for the specifier */
	function = get_handler_function(specifiers_format->specifier);
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

	return (function(specifiers_format, args));
}


/**
 * init_format_info - Initializes a format_specifier_t struct to default values
 * @info: Pointer to the format_specifier_t struct to initialize
 *
 * Description: This function sets all fields of the format_specifier_t struct
 * to default values: flags to 0, width to 0, precision to -1, length to empty
 * string, and specifier to '\0'.
 *
 * Return: void
 */
void init_format_info(format_specifier_t *info)
{
	info->flags = 0;
	info->width = 0;
	info->precision = -1; /* -1 means “not set” */
	info->length[0] = '\0';
	info->specifier = '\0';
}
