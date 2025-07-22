#include "main.h"
#include <stdarg.h>

/**
 * print_unsigned_int - function to print
 * an unsigned int
 *
 * @args: va_list
 *
 * Return: lenght of the print
 */
int print_unsigned_int(va_list args)
{

	int number = va_arg(args, int);
	int digits[10]; /* max integer can only hold 10 digit */
	unsigned int index = 0, num = 0;
	int i, length = 0;

	num = number;

	/* printing zero and leaving if zero is given */
	if (num == 0)
	{
		_putchar('0');
		return (1);
	}

	/* adding last digits to digits array */
	do {
		digits[index] = num % 10;
		num /= 10;
		index++;
	} while (num > 0);

	/* printing number starting from the first digits (index - 1) */
	for (i = index - 1; i >= 0; i--)
	{
		_putchar(digits[i] + '0');
		length++;
	}
	return (length);
}
