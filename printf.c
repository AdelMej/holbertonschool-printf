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
	unsigned int index, i = 0 ;
	char *str;
	va_list daVa;

	handler_t table_print[] = {
		{'c', print_char},
		{"s", print_string},
		{'d', print_number},
		{'i', print_number},
		{NULL, NULL}
	};



	if (format == NULL)
		return (1); /* Error string is null */

	va_start(daVa, format);
	for (index = 0; format[index] != '\0'; index++)
	{
		if (format[index] == '%')
		{
			while (table_print[i].specifier != NULL)
			{
				if (table_print[i].specifier == format[index] + 1)
				{
					table_print[i].print(daVa);
					index++;
					break;
				}
			}
			if (table_print[i].specifier == NULL)/* skipping unknown specifier */
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
