#include "main.h"
#include <stdlib.h>
#include <stdarg.h>

/**
 * octal_to_string_default - Converts an unsigned int to an octal string
 * @args: A va_list containing the unsigned int to convert
 *
 * This function converts an unsigned integer to its octal representation
 * as a string. If the number is 0, it returns a string containing "0".
 * The resulting string is dynamically allocated and must be freed by
 * the caller.
 *
 * Return: Pointer to the newly allocated octal string,
 *         or NULL if memory allocation fails
 */
char *octal_to_string_default(va_list args)
{
	unsigned int number;
	unsigned int size = 0, temp;
	char *str, *ptr;

	number = va_arg(args, unsigned int);

	if (number == 0)
	{
		str = malloc(2);
		if (str == NULL)
			return (NULL);

		str[0] = '0';
		str[1] = '\0';
		return (str);
	}

	temp = number;
	while (temp > 0)
	{
		temp /= 8;
		size++;
	}
	str = malloc(size + 1);
	if (str == NULL)
		return (NULL);

	ptr = convert_base(number, str, 8, "01234567");
	*ptr = '\0';

	return (str);
}

/**
 * octal_to_string_l - Converts an unsigned long to an octal string.
 * @args: A va_list containing the unsigned long to convert.
 *
 * Return: Pointer to a newly allocated string representing the octal
 *         form of the number, or NULL if memory allocation fails.
 *
 * Description: Returns "0" as a string if the number is zero.
 *              Otherwise, calculates the required string size,
 *              allocates memory, and fills it with the octal digits.
 *              The caller is responsible for freeing the returned string.
 */
char *octal_to_string_l(va_list args)
{
	unsigned long number, temp;
	unsigned int size = 0;
	char *str, *ptr;

	number = va_arg(args, unsigned long);

	if (number == 0)
	{
		str = malloc(2);
		if (str == NULL)
			return (NULL);

		str[0] = '0';
		str[1] = '\0';
		return (str);
	}

	temp = number;
	while (temp > 0)
	{
		temp /= 8;
		size++;
	}
	str = malloc(size + 1);
	if (str == NULL)
		return (NULL);

	ptr = convert_base(number, str, 8, "01234567");
	*ptr = '\0';

	return (str);
}

/**
 * octal_to_string_h - Converts an unsigned short to an octal string.
 * @args: A va_list containing the unsigned short to convert.
 *
 * Return: Pointer to a newly allocated string representing the octal
 *         form of the number, or NULL if memory allocation fails.
 *
 * Description: Extracts an unsigned int from the va_list, casts it to
 *              unsigned short, calculates the number of octal digits
 *              needed, allocates memory, and converts the number to
 *              an octal string. Returns "0" as a string if the number is zero.
 *              The caller is responsible for freeing the returned string.
 */
char *octal_to_string_h(va_list args)
{
	unsigned short number, temp;
	unsigned int size = 0;
	char *str, *ptr;

	number = (unsigned short)va_arg(args, unsigned int);

	if (number == 0)
	{
		str = malloc(2);
		if (str == NULL)
			return (NULL);

		str[0] = '0';
		str[1] = '\0';
		return (str);
	}

	temp = number;
	while (temp > 0)
	{
		temp /= 8;
		size++;
	}
	str = malloc(size + 1);
	if (str == NULL)
		return (NULL);

	ptr = convert_base(number, str, 8, "01234567");
	*ptr = '\0';

	return (str);
}

/**
 * octal_to_string_hh - Converts an unsigned char to an octal string.
 * @args: A va_list containing the unsigned char to convert.
 *
 * Return: Pointer to a newly allocated string representing the octal
 *         form of the number, or NULL if memory allocation fails.
 *
 * Description: Extracts an unsigned int from the va_list, casts it to
 *              unsigned char, calculates the number of octal digits
 *              required, allocates memory, and converts the number to
 *              an octal string. Returns "0" as a string if the number is zero.
 *              The caller is responsible for freeing the returned string.
 */
char *octal_to_string_hh(va_list args)
{
	unsigned char number, temp;
	unsigned int size = 0;
	char *str, *ptr;

	number = (unsigned char)va_arg(args, unsigned int);

	if (number == 0)
	{
		str = malloc(2);
		if (str == NULL)
			return (NULL);

		str[0] = '0';
		str[1] = '\0';
		return (str);
	}

	temp = number;
	while (temp > 0)
	{
		temp /= 8;
		size++;
	}
	str = malloc(size + 1);
	if (str == NULL)
		return (NULL);

	ptr = convert_base(number, str, 8, "01234567");
	*ptr = '\0';

	return (str);
}
