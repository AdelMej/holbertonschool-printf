#include "main.h"
#include <stdarg.h>
/* function delcaration*/
unsigned int print_octale_helper(unsigned int number, int *lenght);

/**
 * print_octale - function to convert to octale
 *
 * @args: it's a va_list
 *
 * Return: length of string
 */

int print_octale(va_list args)
{
	unsigned int number = 0;
	int lenght = 0;

	number = va_arg(args, unsigned int);

	if (number == 0)
	{
		_putchar('0');
		return (1);
	}

	print_octale_helper(number, &lenght);

	return (lenght);

}
/**
 * print_octale_helper - function to print octale
 *
 * @number: the number
 * @lenght: size of octale
 *
 * Return: lenght of the print
 */
unsigned int print_octale_helper(unsigned int number, int *lenght)
{
	if (number == 0)
	{
		return (0);
	}
	print_octale_helper(number / 8, lenght);
	_putchar((number % 8) + '0');
	*lenght += 1;

	return (number);
}
