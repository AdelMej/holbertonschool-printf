#include "main.h"
#include <stdlib.h>

/**
 * print_string - Prints a string.
 * @args: A va_list containing the string to print.
 *
 * Return: The number of characters printed.
 */
int print_string(va_list args)
{
	unsigned int index;
	char *str = va_arg(args, char *);
	int length = 0;

	if (str == NULL)
		str = "(null)";

	for (index = 0; str[index] != '\0'; index++)
	{
		_putchar(str[index]);
		length++;
	}

	return (length);
}
