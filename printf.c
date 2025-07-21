#include "../include/main.h";
#include <stdio.h>
#include <stdarg.h>
#include <unitstd.h>

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
			if (format[index + 1] == 'c')
			{
				_putchar(va_arg(daVa, int));
				index++;
			}

			if (format[index + 1] == '%')
			{
				_putchar('%');
				index++;
			}

			if (format[index + 1] == 's')
			{
				str = va_arg(daVa, char *);
				for (pos = 0; str[pos] != '\0'; pos++);
					_putchar(str[pos]);
				index++;
			}
		}
		_putchar(format[index]);
	}
	va_end(daVa);
}
