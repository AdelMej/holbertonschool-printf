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
	unsigned int index, i = 0, length = 0;
	va_list args;
	handler_t table_print[] = {
		{'c', print_char},
		{'s', print_string},
		{'d', print_number},
		{'i', print_number},
		{'\0', NULL}
	};
	if (format == NULL)
		return (-1); /* Error string is null */
	va_start(args, format);
	for (index = 0; format[index] != '\0'; index++)
	{
		if (format[index] == '%')
		{
			i = 0;

			if (format[index + 1] == '%')
				index++;

			while (table_print[i].specifier != '\0')
			{
				if (table_print[i].specifier == format[index + 1])
				{
					length += table_print[i].print(args);
					index++;
					break;
				}
				i++;
			}
			if (table_print[i].specifier == '\0')/* skipping unknown specifier */
				_putchar(format[index]);
		}
		else
			_putchar(format[index]);
		length++;
	}
	va_end(args);
	return (length);
}

/**
* print_char - a function to print a char
* @args: a va_list
*
* Return: void
*/
int print_char(va_list args)
{
	char c = va_arg(args, int);

	_putchar(c);
	return (1);
}

/**
* print_string - helper function to print a string
* @args: a va_list
*
* Return: void
*/
int print_string(va_list args)
{
	unsigned int index;
	char *str = va_arg(args, char *);
	int length = 0;

	if (str == NULL)
		return (-1);

	for (index = 0; str[index] != '\0'; index++)
	{
		_putchar(str[index]);
		length++;
	}

	return (length);
}

/**
* print_number - helper function to print a number
* @args: a va_list
*
* Return: the length of the print
* -1 if failed
*/
int print_number(va_list args)
{
	int number = va_arg(args, int);
	int digits[11]; /* max integer can only hold 10 digit plus one for overflow */
	unsigned int index = 0;
	int i, length = 0;

	/* dealing with negative number */
	if (number < 0)
	{
		_putchar('-');
		number = -number;
	}

	/* printing zero and leaving if zero is given */
	if (number == 0)
	{
		_putchar('0');
		return (1);
	}

	/* adding last digits to digits aray */
	do {
		digits[index] = number % 10;
		number /= 10;
		index++;
	} while (number > 0);

	/* printing number starting from the first digits (index - 1) */
	for (i = index - 1; i >= 0; i--)
	{
		_putchar(digits[i] + '0');
		length++;
	}
	return (length);
}
