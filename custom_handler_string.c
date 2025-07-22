#include "main.h"
#include <stdarg.h>

/**
 * custom_print_string - FUnction to handler
 * custom %S specifier
 *
 * @args: va_list
 *
 * Return: lenght of string
 */

int custom_print_string(va_list args)
{
	unsigned int i;
	int lenght = 0;
	char *to_print;

	to_print = va_arg(args, char *);

	for (i = 0; to_print[i] != '\0'; i++)
	{
		if (to_print[i] > 32 && to_print[i] < 127)
		{
			_putchar(to_print[i]);
			lenght++;
		}
		else
		{
			_putchar('\\');
			_putchar('x');
			if (to_print[i] < 16)
				_putchar('0');
			_printf("%X", to_print[i]);
			lenght += 4;
		}
	}
	return (lenght);
}
