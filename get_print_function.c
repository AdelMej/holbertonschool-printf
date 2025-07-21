#include "main.h"
#include <stdlib.h>

/**
* get_print_function - a function that returns a pointer to
* a function that returns an int and takes a va_list in parameter
*
* @c: the specifier to test
* Return: the function pointer on success
* NULL on fail
*/
print_func_t get_print_function(char c)
{
	unsigned int i;

	handler_t table_print[] = {
		{'c', print_char},
		{'s', print_string},
		{'d', print_number},
		{'i', print_number},
		{'\0', NULL}
	};

	for (i = 0; table_print[i].specifier != '\0'; i++)
		if (table_print[i].specifier == c)
			return (table_print[i].print);

	return (NULL);
}

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
* print_string - helper function to print a string
* @args: a va_list
*
* Return: the number of character printed
*/
int print_string(va_list args)
{
	unsigned int index;
	char *str = va_arg(args, char *);
	int length = 0;

	if (str == NULL)
		str = "(null)";

	for (index = 0; str[index] != '\0'; index++)
	{
		_putchar(str[index]);
		length++;
	}

	return (length);
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
	int digits[10]; /* max integer can only hold 10 digit plus one for overflow */
	unsigned int index = 0, num = 0;
	int i, length = 0;

	/* dealing with negative number */
	if (number < 0)
	{
		_putchar('-');
		num = -number;
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

	/* adding last digits to digits aray */
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
