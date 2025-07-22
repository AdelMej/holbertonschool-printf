#include "main.h"
#include <stdarg.h>
/* Function declarations */
void print_hexa_upper_helper(unsigned int number, int *length);
void print_hexa_lower_helper(unsigned int number, int *length);

/**
 * print_hexa_upper - Prints an unsigned int in uppercase hexadecimal.
 * @args: A va_list containing the unsigned int to print.
 *
 * Return: The number of characters printed.
 */
int print_hexa_upper(va_list args)
{
	unsigned int number;
	int length = 0;

	number = va_arg(args, unsigned int);

	if (number == 0)
	{
		_putchar('0');
		return (1);
	}

	print_hexa_upper_helper(number, &length);

	return (length);
}


/**
 * print_hexa_upper_helper - Recursively prints an unsigned int
 * as uppercase hex.
 * @number: The number to print.
 * @length: Pointer to an int tracking the number of printed characters.
 *
 * Return: void.
 */
void print_hexa_upper_helper(unsigned int number, int *length)
{
	char *hexa_value = "0123456789ABCDEF";

	if (number == 0)
		return;

	print_hexa_upper_helper(number / 16, length);
	_putchar(hexa_value[number % 16]);
	(*length)++;
}


/**
 * print_hexa_lower - Prints an unsigned int in
 * lowercase hexadecimal.
 * @args: A va_list containing the unsigned int to print.
 *
 * Return: The number of characters printed.
 */
int print_hexa_lower(va_list args)
{
	unsigned int number;
	int length = 0;

	number = va_arg(args, unsigned int);

	if (number == 0)
	{
		_putchar('0');
		return (1);
	}

	print_hexa_lower_helper(number, &length);

	return (length);

}


/**
 * print_hexa_lower_helper - Recursively prints an unsigned int
 * as lowercase hex.
 * @number: The number to print.
 * @length: Pointer to an int tracking the number of printed characters.
 *
 * Return: void.
 */
void print_hexa_lower_helper(unsigned int number, int *length)
{
	char *hexa_value = "0123456789abcdef";

	if (number == 0)
		return;
	print_hexa_lower_helper(number / 16, length);
	_putchar(hexa_value[number % 16]);
	(*length)++;
}
