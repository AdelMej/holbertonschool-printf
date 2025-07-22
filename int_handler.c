#include "main.h"

/**
* print_char - a function to print a char
* @args: a va_list
*
* Return: void
*/
int print_char(va_list args)
{
	char c = va_arg(args, int);

	_putchar(c);
	return (1);
}

/**
* print_number - helper function to print a number
* @args: a va_list
*
* Return: the length of the print
*/
int print_number(va_list args)
{
	int number = va_arg(args, int);
	int digits[10]; /* max integer can only hold 10 digit */
	unsigned int index = 0, num = 0;
	int i, length = 0;

	if (number < 0)
	{
		_putchar('-');
		num = (unsigned int)(-number); /* storing absolute value of number */
		length++;
	}
	else
	{
		num = number;
	}

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
