#include "main.h"

/**
 * print_char - Prints a character.
 * @args: A va_list containing the character to print.
 *
 * Return: Number of characters printed (always 1).
 */
int print_char(va_list args)
{
	char c = va_arg(args, int);

	_putchar(c);
	return (1);
}

/**
 * print_number - Prints an integer number.
 * @args: A va_list containing the integer to print.
 *
 * Return: Number of characters printed.
 */
int print_number(va_list args)
{
	int number = va_arg(args, int);
	int digits[10]; /* Maximum digits for an int */
	unsigned int index = 0, num = 0;
	int i, length = 0;

	if (number < 0)
	{
		_putchar('-');
		num = (unsigned int)(-(long)number); /* Store absolute value */
		length++;
	}
	else
	{
		num = (unsigned int)number;
	}

	/* Print '0' if number is zero */
	if (num == 0)
	{
		_putchar('0');
		return (length + 1); /* Include '-' if printed */
	}

	/* Store digits in reverse order */
	do {
		digits[index] = num % 10;
		num /= 10;
		index++;
	} while (num > 0);

	/* Print digits in correct order */
	for (i = index - 1; i >= 0; i--)
	{
		_putchar(digits[i] + '0');
		length++;
	}
	return (length);
}
