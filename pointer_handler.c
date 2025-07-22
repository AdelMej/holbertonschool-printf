#include "main.h"
#include <stdarg.h>
#include <stdlib.h>

/* Function declarations */
void print_pointer_helper(unsigned long address, int *length);

/**
 * print_pointer - Prints a pointer address in hexadecimal format.
 * @args: va_list containing the pointer to print.
 *
 * Return: Number of characters printed.
 */
int print_pointer(va_list args)
{
	void *ptr = va_arg(args, void *);
	int length = 2;

	if (ptr == NULL)
		return (print_nil);

	_putchar('0');
	_putchar('x');

	print_pointer_helper((unsigned long)ptr, &length);

	return (length);
}

/**
 * print_pointer_helper - Recursively prints an unsigned long integer
 *                       as a lowercase hexadecimal number.
 * @address: The unsigned long integer to print.
 * @length: The length of the print
 *
 * Description:
 * Recursively divides the address by 16 and prints the hexadecimal
 * digits corresponding to the remainder.
 * Does not print the "0x" prefix.
 */
void print_pointer_helper(unsigned long address, int *length)
{
	static const char *tab_hexa = "0123456789abcdef";

	if (address == 0)
		return;

	print_pointer_helper(address / 16, length);
	_putchar(tab_hexa[address % 16]);
	(*length)++;
}

/**
 * print_nil - Prints the string "(nil)".
 *
 * Return: The number of characters printed (always 5).
 *
 * Description:
 * Used to handle printing of NULL pointers in a human-readable format,
 * following the standard `(nil)` representation.
 */
int print_nil(void)
{
	_putchar('(');
	_putchar('n');
	_putchar('i');
	_putchar('l');
	_putchar(')');
	return (5);
}
