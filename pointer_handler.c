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
	int length;
	unsigned long address;

	_putchar('0');
	_putchar('x');
	length = 2;

	if (ptr == NULL)
	{
		_putchar('0');
		return (length + 1);
	}
	address = (unsigned long)ptr;
	print_pointer_helper(address, &length);

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
	char *tab_hexa = "0123456789abcdef";

	if (address == 0)
		return;

	print_pointer_helper(address / 16, length);
	_putchar(tab_hexa[address % 16]);
	(*length)++;
}
