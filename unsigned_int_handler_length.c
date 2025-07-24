#include "main.h"
#include <stdlib.h>
#include <stdarg.h>
/**
 * uint_to_string - Converts an unsigned int from va_list to a string.
 * @args: A va_list containing the unsigned int to convert.
 *
 * Return: Pointer to a newly allocated string representing the number,
 *         or NULL if memory allocation fails.
 *
 * Description: Allocates sufficient memory to store the string
 *              representation of the unsigned int including the null
 *              terminator. Returns "0" as a string if number is zero.
 *              The caller is responsible for freeing the returned string.
 */
char *uint_to_string_default(va_list args)
{
	unsigned int number = va_arg(args, unsigned int);
	char *str;
	unsigned int size, temp, i;

	size = _sizeofuint(number);
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
		temp = number;

	for (i = 0; temp > 0; i++)
	{
		str[size - i - 2] = (temp % 10) + '0';
		temp /= 10;
	}

	return (str);
}

/**
 * uint_to_string - Converts an unsigned int from va_list to a string.
 * @args: A va_list containing the unsigned int to convert.
 *
 * Return: Pointer to a newly allocated string representing the number,
 *         or NULL if memory allocation fails.
 *
 * Description: Allocates sufficient memory to store the string
 *              representation of the unsigned int including the null
 *              terminator. Returns "0" as a string if number is zero.
 *              The caller is responsible for freeing the returned string.
 */
char *uint_to_string_l(va_list args)
{
	unsigned long number = va_arg(args, unsigned long);
	char *str;
	unsigned int size, i;
	unsigned long temp;

	size = _sizeofulong(number);
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
		temp = number;

	for (i = 0; temp > 0; i++)
	{
		str[size - i - 2] = (temp % 10) + '0';
		temp /= 10;
	}

	return (str);
}

/**
 * uint_to_string_h - Converts an unsigned short int to a string.
 * @args: va_list containing the unsigned short integer.
 *
 * Return: Pointer to a newly allocated string representing the number,
 *         or NULL if memory allocation fails.
 *
 * Description: Handles conversion of an unsigned short integer to
 *              its decimal string representation. Handles 0 specially
 *              and ensures proper memory allocation. Caller must free.
 */
char *uint_to_string_h(va_list args)
{
	unsigned short number = (unsigned short)va_arg(args, unsigned int);
	char *str;
	unsigned int size, i;
	unsigned short temp;

	size = _sizeofushort(number);
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
		temp = number;

	for (i = 0; temp > 0; i++)
	{
		str[size - i - 2] = (temp % 10) + '0';
		temp /= 10;
	}

	return (str);
}

/**
 * uint_to_string_hh - Converts an unsigned char to a string.
 * @args: va_list containing the unsigned char (promoted to int).
 *
 * Return: Pointer to a newly allocated string representing the number,
 *         or NULL if memory allocation fails.
 *
 * Description: Handles conversion of an unsigned char to its decimal
 *              string representation. Special case for 0. The caller
 *              is responsible for freeing the returned string.
 */
char *uint_to_string_hh(va_list args)
{
	unsigned char number = (unsigned char)va_arg(args, unsigned int);
	char *str;
	unsigned int size, i;
	unsigned char temp;

	size = _sizeofuchar(number);
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
		temp = number;

	for (i = 0; temp > 0; i++)
	{
		str[size - i - 2] = (temp % 10) + '0';
		temp /= 10;
	}

	return (str);
}
