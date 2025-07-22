#include "main.h"
#include <stdarg.h>
/*function delaration */
unsigned int print_hexa_upper_helper(unsigned int number, int *lenght);
unsigned int print_hexa_lower_helper(unsigned int number, int *lenght);


/**
 * print_hexa_upper - function to convert to
 * hexadecimal in uppercase
 *
 * @args: it's a va_list
 *
 * Return: length of string
 */

int print_hexa_upper(va_list args)
{
	unsigned int number = 0;
	int lenght = 0;

	number = va_arg(args, unsigned int);

	if (number == 0)
	{
		_putchar('0');
		return (1);
	}

	print_hexa_upper_helper(number, &lenght);

	return (lenght);

}
/**
 * print_hexa_upper_helper - function to
 * print hexadecimal in uppercase
 *
 * @number: the number
 * @lenght: size of hexadecimal
 *
 * Return: lenght of the print
 */
unsigned int print_hexa_upper_helper(unsigned int number, int *lenght)
{
	char *hexa_value = "0123456789ABCDEF";

	if (number == 0)
	{
		return (0);
	}
	print_hexa_upper_helper(number / 16, lenght);
	_putchar(hexa_value[number % 16]);
	*lenght += 1;

	return (number);
}


/**
 * print_hexa_lower - function to convert to
 * hexadecimal in lowercase
 *
 * @args: it's a va_list
 *
 * Return: length of string
 */

int print_hexa_lower(va_list args)
{
	unsigned int number = 0;
	int lenght = 0;

	number = va_arg(args, unsigned int);

	if (number == 0)
	{
		_putchar('0');
		return (1);
	}

	print_hexa_lower_helper(number, &lenght);

	return (lenght);

}
/**
 * print_hexa_lower_helper - function to
 * print hexadecimal in lowercase
 *
 * @number: the number
 * @lenght: size of hexadecimal
 *
 * Return: lenght of the print
 */
unsigned int print_hexa_lower_helper(unsigned int number, int *lenght)
{
	char *hexa_value = "0123456789abcdef";

	if (number == 0)
	{
		return (0);
	}
	print_hexa_lower_helper(number / 16, lenght);
	_putchar(hexa_value[number % 16]);
	*lenght += 1;

	return (number);
}
