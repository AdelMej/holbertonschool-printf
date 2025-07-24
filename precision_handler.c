#include "main.h"
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
/**
 * string_precision_handler - applies precision to a string conversion
 * @fmt: pointer to the format specifier struct containing precision info
 * @str: string to be truncated according to precision
 *
 * Description: 
 *   - If the precision is zero, returns an empty string.
 *   - If the precision is less than the length of the string,
 *     returns a new truncated string of length precision.
 *   - Otherwise, returns the original string unchanged.
 *   - Frees the original string when a new string is allocated.
 *
 * Return: pointer to the new or original string on success,
 *         NULL if malloc fails.
 */
char *string_precision_handler(format_specifier_t *fmt, char *str)
{
	int size = 0, i;
	char *new_str;

	if (str == NULL)
		return (NULL);

	if (fmt->precision < 0)
	{
		return (str);
	}

	if (fmt->precision == 0)
	{
		free(str);
		new_str = malloc(1);
		if (new_str == NULL)
			return (NULL);
		*new_str = '\0';
		return (new_str); /* for malloc(1) + '\0' */
	}
	size = _strlen(str);
	if (fmt->precision < size)
	{
		new_str = malloc(fmt->precision + 1);
		if (new_str == NULL)
			return (NULL);

		for (i = 0; i < fmt->precision; i++)
		{
			new_str[i] = str[i];
		}
		new_str[i] = '\0';
		free(str);
		return (new_str);
	}
	else
	{
		return (str);
	}
}

/**
 * int_precision_handler - applies precision formatting to integer strings
 * @fmt: pointer to format_specifier_t struct containing formatting options
 * @str: string representation of the integer to format
 *
 * This function adjusts the integer string according to the precision specified
 * in fmt->precision. If the precision is zero, it returns an empty string.
 * If the precision is greater than the length of the integer string, the
 * function pads the number with leading zeros. It handles negative numbers
 * by preserving the minus sign at the front.
 *
 * The original string is freed before returning the newly allocated string.
 *
 * Return: pointer to a newly allocated formatted string or the original string
 *         if no changes are needed. Returns NULL on malloc failure.
 */
char *int_precision_handler(format_specifier_t *fmt, char *og_str)
{
	int size = 0, i, digits;
	char *new_str, *ptr, *str;

	str = og_str;
	if (str == NULL)
		return (NULL);

	size = _strlen(str);
	if (fmt->precision == 0 && size == 1 && str[0] == '0')
	{
		new_str = malloc(1);
		if (new_str == NULL)
			return (NULL);
		new_str[0] = '\0';
		free(str);
		return (new_str);
	}
	else if (fmt->precision == 0)
	{
		return (str);
	}
	digits = size;
	if (str[0] == '-' || str[0] == '+')
		digits = size - 1;

	if (fmt->precision > digits)
	{
		if (str[0] == '-')
		{
			new_str = malloc(fmt->precision + 2);
			if (new_str == NULL)
				return  (NULL);
			ptr = new_str;
			*ptr = '-';
			ptr++;
			str++;
			size--;
		}
		else
		{
			new_str = malloc(fmt->precision + 1);
			if (new_str == NULL)
				return (NULL);
			ptr = new_str;
		}
		i = 0;
		while (i < fmt->precision - digits)
		{
			*ptr = '0';
			ptr++;
			i++;
		}
		for (i = 0; str[i] != '\0'; i++)
		{
			*ptr = str[i];
			ptr++;
		}
		*ptr = '\0';
		free(og_str);
		return (new_str);
	}

	return (str);
}
