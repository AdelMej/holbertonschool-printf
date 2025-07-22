#include "main.h"
#include <stdarg.h>
#include <stdlib.h>
/* Function declarations */
void custom_print_hex_helper(char str);

/**
 * custom_print_string - Function to handle custom %S specifier
 * @args: va_list containing the string to print
 *
 * Return: Number of characters printed
 *
 * This function prints a string. Printable characters (ASCII 33 to 126)
 * are printed as-is. Non-printable characters are printed as \xNN,
 * where NN is the uppercase hexadecimal representation of the character.
 * If the string is NULL, prints "(null)".
 */
int custom_print_string(va_list args)
{
	unsigned int i;
	int length = 0;
	char *to_print;

	to_print = va_arg(args, char *);
	if (to_print == NULL)
		to_print = "(null)";

	for (i = 0; to_print[i] != '\0'; i++)
	{
		if (to_print[i] > 32 && to_print[i] < 127)
		{
			_putchar(to_print[i]);
			length++;
		}
		else
		{
			_putchar('\\');
			_putchar('x');
			custom_print_hex_helper(to_print[i]);
			length += 4;
		}
	}
	return (length);
}

/**
 * custom_print_hex_helper - Prints a byte as two hexadecimal characters.
 * @str: Pointer to the unsigned char byte to print.
 *
 * This function takes a pointer to a byte, extracts its high and low nibbles,
 * converts each nibble to its hexadecimal character, and prints them using
 * _putchar.
 *
 * The high nibble is obtained by shifting the byte 4 bits to the right.
 * The low nibble is obtained by masking the byte with 0x0F.
 *
 * Example:
 * If *str is 0xAB, the function will print "AB".
 */
void custom_print_hex_helper(char str)
{
	const char *hex_digits = "0123456789ABCDEF";

	int high = str >> 4; /* getting high nibble */
	int low = str & 0x0F; /* getting low nibble */

	_putchar(hex_digits[high]); /* printing high nibble */
	_putchar(hex_digits[low]); /* printing low nibble */
}
