#include "main.h"
#include <stdlib.h>
#include <stdarg.h>

/**
 * int_to_string_default - Converts an int argument from va_list
 *                        to its string representation.
 * @args: A va_list containing the int to convert.
 *
 * This function retrieves an int from the va_list, allocates enough memory
 * to store its string representation including the sign and NULL terminator,
 * then fills the allocated string with the decimal digits of the number.
 * Handles zero and negative numbers properly.
 *
 * Return: Pointer to the newly allocated string representing the integer,
 *         or NULL if memory allocation fails.
 */
char *int_to_string_default(va_list args)
{
	unsigned int i, size = 0;
	int number = va_arg(args, int);
	unsigned int temp;
	char *str;

	size = _sizeofint(number);
	str = malloc(size);
	if (str == NULL)
		return (NULL);

	if (number == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}

	str[size - 1] = '\0';
	if (number < 0)
	{
		temp = (unsigned int)(-(long)number);
		str[0] = '-';
	}
	else
	{
		temp = (unsigned int)number;
	}

	for (i = 0; temp > 0; i++)
	{
		str[size - i - 2] = (temp % 10) + '0';
		temp /= 10;
	}

	return (str);
}

/**
 * int_to_string_l - Converts a long integer from a va_list
 *                   to its string representation.
 * @args: A va_list containing the long integer to convert.
 *
 * This function retrieves a long integer from the va_list, calculates
 * the required string size, allocates memory, and then converts the
 * number to a NULL-terminated string. Handles zero and negative values
 * correctly.
 *
 * Return: Pointer to a newly allocated string representing the long integer,
 *         or NULL if memory allocation fails.
 */
char *int_to_string_l(va_list args)
{
	unsigned int i, size = 0;
	long number = va_arg(args, long);
	unsigned long temp;
	char *str;

	size = _sizeoflong(number);
	str = malloc(size);
	if (str == NULL)
		return (NULL);

	if (number == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}

	str[size - 1] = '\0';
	if (number < 0)
	{
		temp = (unsigned long)(-number);
		str[0] = '-';
	}
	else
	{
		temp = (unsigned long)number;
	}

	for (i = 0; temp > 0; i++)
	{
		str[size - i - 2] = (temp % 10) + '0';
		temp /= 10;
	}

	return (str);
}

/**
 * int_to_string_h - Converts a short integer from a va_list
 *                   to its string representation.
 * @args: A va_list containing the integer argument (promoted to int).
 *
 * This function extracts a short integer (promoted to int) from the va_list,
 * calculates the required string size, allocates memory, and converts the
 * number to a NULL-terminated string. It handles zero and negative values.
 *
 * Return: Pointer to a newly allocated string representing the short integer,
 *         or NULL if memory allocation fails.
 */
char *int_to_string_h(va_list args)
{
	unsigned int i, size = 0;
	short number = (short)va_arg(args, int);
	unsigned short temp;
	char *str;

	size = _sizeofshort(number);
	str = malloc(size);
	if (str == NULL)
		return (NULL);

	if (number == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}

	str[size - 1] = '\0';
	if (number < 0)
	{
		temp = (unsigned short)(-number);
		str[0] = '-';
	}
	else
	{
		temp = (unsigned short)number;
	}

	for (i = 0; temp > 0; i++)
	{
		str[size - i - 2] = (temp % 10) + '0';
		temp /= 10;
	}

	return (str);
}

/**
 * int_to_string_hh - Converts a signed char integer from a va_list
 *                    to its string representation.
 * @args: A va_list containing the integer argument (promoted to int).
 *
 * This function extracts a signed char (promoted to int) from the va_list,
 * calculates the required string size, allocates memory, and converts the
 * number to a NULL-terminated string. It handles zero and negative values.
 *
 * Return: Pointer to a newly allocated string representing the signed char,
 *         or NULL if memory allocation fails.
 */
char *int_to_string_hh(va_list args)
{
	unsigned int i, size = 0;
	signed char number = (signed char)va_arg(args, int);
	unsigned char temp;
	char *str;

	size = _sizeofchar(number);
	str = malloc(size);
	if (str == NULL)
		return (NULL);

	if (number == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}

	str[size - 1] = '\0';
	if (number < 0)
	{
		temp = (unsigned char)(-number);
		str[0] = '-';
	}
	else
	{
		temp = (unsigned char)number;
	}

	for (i = 0; temp > 0; i++)
	{
		str[size - i - 2] = (temp % 10) + '0';
		temp /= 10;
	}

	return (str);
}
