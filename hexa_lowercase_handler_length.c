#include "main.h"
#include <stdlib.h>
#include <stdarg.h>

/**
 * hexa_lower_to_string_default - Converts an unsigned int to a lowercase
 *                                hexadecimal string.
 * @args: va_list containing the unsigned int to convert.
 *
 * Return: Pointer to a dynamically allocated string representing the number
 *         in lowercase hexadecimal format, or NULL on failure.
 *         The caller is responsible for freeing the returned string.
 */
char *hexa_lower_to_string_default(va_list args)
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

	ptr = convert_base(number, str, 16, "0123456789abcdef");
	*ptr = '\0';

	return (str);
}

/**
 * hexa_lower_to_string_l - Converts an unsigned long to a lowercase
 *                          hexadecimal string.
 * @args: va_list containing the unsigned long to convert.
 *
 * Return: Pointer to a dynamically allocated string representing the number
 *         in lowercase hexadecimal format, or NULL on failure.
 *         The caller is responsible for freeing the returned string.
 */
char *hexa_lower_to_string_l(va_list args)
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

	ptr = convert_base(number, str, 16, "0123456789abcdef");
	*ptr = '\0';

	return (str);
}

/**
 * hexa_lower_to_string_h - Converts an unsigned short to a lowercase
 *                          hexadecimal string.
 * @args: va_list containing the unsigned short (promoted to unsigned int).
 *
 * Return: Pointer to a dynamically allocated string representing the number
 *         in lowercase hexadecimal format, or NULL on failure.
 *         The caller is responsible for freeing the returned string.
 */
char *hexa_lower_to_string_h(va_list args)
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

	ptr = convert_base(number, str, 16, "0123456789abcdef");
	*ptr = '\0';

	return (str);
}

/**
 * hexa_lower_to_string_hh - Converts an unsigned char to a lowercase
 *                           hexadecimal string.
 * @args: va_list containing the unsigned char (promoted to unsigned int).
 *
 * Return: Pointer to a dynamically allocated string representing the number
 *         in lowercase hexadecimal format, or NULL on failure.
 *         The caller is responsible for freeing the returned string.
 */
char *hexa_lower_to_string_hh(va_list args)
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

	ptr = convert_base(number, str, 16, "0123456789abcdef");
	*ptr = '\0';

	return (str);
}
