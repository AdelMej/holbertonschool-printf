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
			ptr = flag_handler((char *)ptr, &specifiers_format);

			res = format_handler(*ptr, args);
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
