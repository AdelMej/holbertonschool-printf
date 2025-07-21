#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
* _printf - a function that mimic standard printf
* @format: a string to print with format
*
* Return: string length if it succeed
* -1 if it fails
*/
int _printf(const char *format, ...)
{
	unsigned int index, length = 0;
	int res;
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
				return (-1); /* error incorrect parsing */
			
			res = format_handler(format[index + 1], args);
			if (res == -1)
				return (-1); /* failed parsing */
			else
				length += res;

			index++; /* skip next character */
		}
		else
		{
			_putchar(format[index]);
			length++;
		}
	}
	va_end(args);
	return (length);
}

/**
* format_handler - a function to handle a format
* @specifier: the specifier to test
* @args: a va_list
*
* Return: -1 on fail
* string length on success
*/
int format_handler(char specifier, va_list args)
{
	print_func_t function;
	int res;

	if (specifier == '\0')
		return (-1); /* error incorrect parsing */

	if (specifier == '%') /* printing % if next character is a % */
	{
		_putchar('%');
		return (1);
	}
	/* getting the correct function for the specifier */
	function = get_print_function(specifier);
	if (function == NULL) /* skipping unknown specifier */
	{
		_putchar('%');
		_putchar(specifier);
		return (2);
	}
	res = function(args);
	if (res == -1) /* failed parsing */
		return (-1);

	return(res);
}
