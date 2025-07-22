#include "main.h"
#include <stdarg.h>
/*function delaration */
void print_binary_helper(unsigned int number, int *length);


/**
 * print_binary - function to convert to binary
 *
 * @args: it's a va_list
 *
 * Return: length of string
 */

int print_binary(va_list args)
{
	unsigned int number = 0;
	int length = 0;

	number = va_arg(args, unsigned int);

	if (number == 0)
	{
		_putchar('0');
		return (1);
	}

	print_binary_helper(number, &length);

	return (length);

}
/**
 * print_binary_helper - function to print binary
 *
 * @number: the number
 * @length: size of binary
 *
 * Return: length of the print
 */
void print_binary_helper(unsigned int number, int *length)
{
	if (number == 0)
		return;

	print_binary_helper(number / 2, length);
	_putchar((number % 2) + '0');
	(*length)++;
}
