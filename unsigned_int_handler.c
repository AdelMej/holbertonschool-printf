#include "main.h"
#include <stdarg.h>

/**
 * print_unsigned_int - Prints an unsigned int.
 * @args: A va_list containing the unsigned int to print.
 *
 * Return: The number of characters printed.
 */
int print_unsigned_int(va_list args)
{
	unsigned int number = va_arg(args, unsigned int);
	int digits[10]; /* Maximum digits for unsigned int */
	unsigned int index = 0;
	int i, length = 0;

	/* Print '0' if number is zero and return */
	if (number == 0)
	{
		_putchar('0');
		return (1);
	}

	/* Store digits in reverse order */
	do {
		digits[index] = number % 10;
		number /= 10;
		index++;
	} while (number > 0);

	/* Print digits in correct order */
	for (i = index - 1; i >= 0; i--)
	{
		_putchar(digits[i] + '0');
		length++;
	}

	return (length);
}
