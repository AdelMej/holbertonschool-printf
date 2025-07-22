#include "main.h"
#include <stdarg.h>
/* Function declarations */
void print_octal_helper(unsigned int number, int *length);

/**
 * print_octal - Prints an unsigned int in octal format.
 * @args: A va_list containing the unsigned int to print.
 *
 * Return: The number of characters printed.
 */
int print_octal(va_list args)
{
	unsigned int number;
	int length = 0;

	number = va_arg(args, unsigned int);

	if (number == 0)
	{
		_putchar('0');
		return (1);
	}

	print_octal_helper(number, &length);

	return (length);
}


/**
 * print_octal_helper - Recursively prints an unsigned int as octal.
 * @number: The number to print.
 * @length: Pointer to an int tracking the number of printed characters.
 *
 * Return: void.
 */
void print_octal_helper(unsigned int number, int *length)
{
	if (number == 0)
		return;

	print_octal_helper(number / 8, length);
	_putchar((number % 8) + '0');
	(*length)++;
}
