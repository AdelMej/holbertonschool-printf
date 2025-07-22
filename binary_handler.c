#include "main.h"
#include <stdarg.h>
/*function delaration */
unsigned int print_binary_helper(unsigned int number, int *lenght);


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
	int lenght = 0;

	number = va_arg(args, unsigned int);

	if (number == 0)
	{
		_putchar('0');
		return (1);
	}

	print_binary_helper(number, &lenght);

	return (lenght);

}
/**
 * print_binary_helper - function to print binary
 *
 * @number: the number
 * @lenght: size of binary
 *
 * Return: lenght of the print
 */
unsigned int print_binary_helper(unsigned int number, int *lenght)
{
	if (number == 0)
	{
		return (0);
	}
	print_binary_helper(number / 2, lenght);
	_putchar((number % 2) + '0');
	*lenght += 1;

	return (number);
}
