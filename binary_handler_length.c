#include "main.h"
#include <stdlib.h>

/**
 * binary_to_string_default - Converts an unsigned int to a binary string.
 * @args: A va_list containing the unsigned int to convert.
 *
 * Return: Pointer to a newly allocated string representing the binary
 *         form of the number, or NULL if memory allocation fails.
 *
 * Description: If the number is zero, returns the string "0".
 *              Otherwise, calculates the number of binary digits needed,
 *              allocates memory, and uses convert_base to fill the string.
 *              The caller is responsible for freeing the returned string.
 */
char *binary_to_string_default(va_list args)
{
	unsigned int number = 0, temp, size = 0;
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
		temp /= 2;
		size++;
	}

	str = malloc(size + 1);
	if (str == NULL)
		return (NULL);

	ptr = convert_base(number, str, 2, "01");
	*ptr = '\0';

	return (str);
}

/**
 * binary_to_string_l - Converts an unsigned long to a binary string.
 * @args: A va_list containing the unsigned long to convert.
 *
 * Return: Pointer to a newly allocated string representing the binary
 *         form of the number, or NULL if memory allocation fails.
 *
 * Description: If the number is zero, returns the string "0".
 *              Otherwise, calculates the number of binary digits needed,
 *              allocates memory, and uses convert_base to fill the string.
 *              The caller is responsible for freeing the returned string.
 */
char *binary_to_string_l(va_list args)
{
	unsigned long number = 0, temp;
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
		temp /= 2;
		size++;
	}

	str = malloc(size + 1);
	if (str == NULL)
		return (NULL);

	ptr = convert_base(number, str, 2, "01");
	*ptr = '\0';

	return (str);
}

/**
 * binary_to_string_h - Converts an unsigned short to a binary string.
 * @args: A va_list containing the unsigned short (promoted to int) to convert.
 *
 * Return: Pointer to a newly allocated string representing the binary
 *         form of the number, or NULL if memory allocation fails.
 *
 * Description: Handles the %h length modifier for binary output.
 *              If the number is 0, returns the string "0".
 *              Otherwise, calculates the binary size, allocates memory,
 *              and uses convert_base to fill the result string.
 *              Caller must free the returned string.
 */
char *binary_to_string_h(va_list args)
{
	unsigned short number = 0, temp;
	unsigned int size = 0;
	char *str, *ptr;

	number = (unsigned short)va_arg(args, int);

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
		temp /= 2;
		size++;
	}

	str = malloc(size + 1);
	if (str == NULL)
		return (NULL);

	ptr = convert_base(number, str, 2, "01");
	*ptr = '\0';

	return (str);
}

/**
 * binary_to_string_hh - Converts an unsigned char to a binary string.
 * @args: A va_list containing the unsigned char (promoted to int) to convert.
 *
 * Return: Pointer to a newly allocated string representing the binary
 *         form of the number, or NULL if memory allocation fails.
 *
 * Description: Handles the %hh length modifier for binary output.
 *              If the number is 0, returns the string "0".
 *              Otherwise, calculates the number of binary digits needed,
 *              allocates memory, and uses convert_base to fill the string.
 *              Caller must free the returned string.
 */
char *binary_to_string_hh(va_list args)
{
	unsigned char number = 0, temp;
	unsigned int size = 0;
	char *str, *ptr;

	number = (unsigned char)va_arg(args, int);

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
		temp /= 2;
		size++;
	}

	str = malloc(size + 1);
	if (str == NULL)
		return (NULL);

	ptr = convert_base(number, str, 2, "01");
	*ptr = '\0';

	return (str);
}
