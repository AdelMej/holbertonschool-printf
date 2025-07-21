#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 *
 *
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


void print_char(char c)
{
	_putchar(c);
}

void print_string(char *str)
{
	unsigned int index;
	for (index = 0; str[index] != '\0'; index++)
		_putchar(str[index]);
}

void print_number()
{
	
}
