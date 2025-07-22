#include "main.h"
#include <stdlib.h>
/**
* print_string - helper function to print a string
* @args: a va_list
*
* Return: the number of character printed
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
