#include "main.h"

/**
 * convert_base - Recursively converts a number to a string in a given base
 * @number: The number to convert
 * @str: Pointer to the buffer where digits will be written
 * @base: The base to convert to (e.g. 8, 10, 16)
 * @values: String containing the digit characters for the base
 *          (e.g. "0123456789abcdef")
 *
 * This function fills the buffer pointed to by @str with the digits
 * of @number in the specified base. It uses recursion to ensure the
 * digits are written in the correct order. The buffer must be
 * pre-allocated and large enough to hold the result.
 *
 * Return: Pointer to the next available position in the buffer
 */
char *convert_base(unsigned int number, char *str, int base, const char *values)
{
	if (number == 0)
		return (str);

	str = convert_base(number / base, str, base, values);
	*str = values[number % base];
	return (str + 1);
}
