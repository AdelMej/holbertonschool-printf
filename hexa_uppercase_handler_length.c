#include "main.h"
#include <stdlib.h>
#include <stdarg.h>
/**
 * hexa_upper_to_string_default - Converts an unsigned int to uppercase
 *								  hexadecimal string.
 * @args: A va_list containing the unsigned int to convert.
 *
 * Return: Pointer to a newly allocated string representing the uppercase
 *         hexadecimal form of the number, or NULL if memory allocation fails.
 *
 * Description: If the number is zero, returns the string "0".
 *              Otherwise, calculates the required string size,
 *              allocates memory, and fills it using convert_base
 *              with uppercase hex digits.
 *              The caller is responsible for freeing the returned string.
 */
char *hexa_upper_to_string_default(va_list args)
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
		temp /= 16;
		size++;
	}
	str = malloc(size + 1);
	if (str == NULL)
		return (NULL);

	ptr = convert_base(number, str, 16, "0123456789ABCDEF");
	*ptr = '\0';

	return (str);
}

/**
 * hexa_upper_to_string_l - Converts an unsigned long integer to an uppercase
 *                         hexadecimal string.
 * @args: va_list containing the unsigned long integer to convert.
 *
 * Extracts an unsigned long from args and converts it to a string
 * representation in uppercase hexadecimal. Returns a pointer to
 * a newly allocated string or NULL if allocation fails.
 *
 * Return: Pointer to dynamically allocated uppercase hex string,
 *         or NULL on failure.
 */
char *hexa_upper_to_string_l(va_list args)
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
		temp /= 16;
		size++;
	}
	str = malloc(size + 1);
	if (str == NULL)
		return (NULL);

	ptr = convert_base(number, str, 16, "0123456789ABCDEF");
	*ptr = '\0';

	return (str);
}

/**
 * hexa_upper_to_string_h - Converts an unsigned short to uppercase hex string.
 * @args: va_list containing the unsigned short (promoted to unsigned int).
 *
 * Return: Pointer to a newly allocated string containing the uppercase
 *         hexadecimal representation of the number, or NULL if malloc fails.
 *
 * Description: Retrieves the unsigned short from the va_list, converts it to
 *              uppercase hexadecimal string. Returns "0" if number is zero.
 *              Caller must free the returned string.
 */
char *hexa_upper_to_string_h(va_list args)
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
		temp /= 16;
		size++;
	}
	str = malloc(size + 1);
	if (str == NULL)
		return (NULL);

	ptr = convert_base(number, str, 16, "0123456789ABCDEF");
	*ptr = '\0';

	return (str);
}

/**
 * hexa_upper_to_string_hh - Converts an unsigned char to uppercase hex string.
 * @args: va_list containing the unsigned char (promoted to unsigned int).
 *
 * Return: Pointer to a newly allocated string containing the uppercase
 *         hexadecimal representation of the number, or NULL if malloc fails.
 *
 * Description: Retrieves the unsigned char from the va_list, converts it to
 *              uppercase hexadecimal string. Returns "0" if number is zero.
 *              Caller must free the returned string.
 */
char *hexa_upper_to_string_hh(va_list args)
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
		temp /= 16;
		size++;
	}
	str = malloc(size + 1);
	if (str == NULL)
		return (NULL);

	ptr = convert_base(number, str, 16, "0123456789ABCDEF");
	*ptr = '\0';

	return (str);
}
