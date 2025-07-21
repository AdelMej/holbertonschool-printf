#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
* _printf - a function that mimic standard printf
* @format: a string to print with format
*
* Return: 0 if it succeed
* 1 if it fails
*/
int _printf(const char *format, ...)
{
	unsigned int index, i = 0, length = 0;
	va_list daVa;
	handler_t table_print[] = {
		{'c', print_char},
		{'s', print_string},
		{'d', print_number},
		{'i', print_number},
		{'\0', NULL}
	};
	if (format == NULL)
		return (1); /* Error string is null */
	va_start(daVa, format);
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
					table_print[i].print(daVa);
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
	va_end(daVa);
	return (length);
}

/**
* print_char - a function to print a char
* @daVa: a va_list
*
* Return: void
*/
void print_char(va_list daVa)
{
	char c = va_arg(daVa, int);

	_putchar(c);
}

/**
* print_string - helper function to print a string
* @daVa: a va_list
*
* Return: void
*/
void print_string(va_list daVa)
{
	unsigned int index;
	char *str = va_arg(daVa, char *);

	for (index = 0; str[index] != '\0'; index++)
		_putchar(str[index]);
}

/**
* print_number - helper function to print a number
* @daVa: a va_list
*
* Return: void
*/
void print_number(va_list daVa)
{
	int number = va_arg(daVa, int);
	int digits[11]; /* max integer can only hold 10 digit plus one for overflow */
	unsigned int index = 0;
	int i;

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
		return;
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
	}
}
