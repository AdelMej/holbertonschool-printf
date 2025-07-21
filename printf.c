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
	unsigned int index, pos;
	char *str;
	va_list daVa;

	if (format == NULL)
		return (1); /* Error string is null */

	va_start(daVa, format);
	for (index = 0; format[index] != '\0'; index++)
	{
		if (format[index] == '%')
		{
			if (format[index + 1] == 'c') /* printing a char */
			{
				_putchar(va_arg(daVa, int));
				index ++;
			}
			else if (format[index + 1] == '%') /* printing a % */
			{
				_putchar('%');
				index ++;
			}
			else if (format[index + 1] == 's') /* printing a stored string */
			{
				str = va_arg(daVa, char *);
				for (pos = 0; str[pos] != '\0'; pos++)
					_putchar(str[pos]);
				index++;
			}
			else /* skipping unknown specifier */
			{
				index++;
			}
		}
		else
		{
			_putchar(format[index]);
		}
	}
	va_end(daVa);
	return (0);
}

/**
* print_char - a function to print a char
* @daVa a va_list
*
* Return: void
*/
void print_char(va_list daVa)
{
	char c = va_arg(daVa, int);

	_putchar(c);
}

/**
* print_string - gelper function to print a string
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
	int digits[11]; /* max iteger can only hold 10 digit and a negative */
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
	do
	{
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
