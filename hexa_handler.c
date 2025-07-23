#include "main.h"
#include <stdarg.h>
#include <stdlib.h>
/* Function declarations */
char *hexa_upper_helper(unsigned int number, char *str);
char *hexa_lower_helper(unsigned int number, char *str);

/**
 * hexa_upper_to_string - Converts an unsigned int to an uppercase
 * hexadecimal string.
 * @args: A va_list containing the unsigned int to convert.
 *
 * Return: Pointer to a newly allocated string representing the hexadecimal
 *         form of the number in uppercase, or NULL if allocation fails.
 *
 * Description: Returns "0" if the number is 0.
 *              Caller is responsible for freeing the returned string.
 */
char *hexa_upper_to_string(va_list args)
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

	ptr = hexa_upper_helper(number, str);
	*ptr = '\0';

	return (str);
}


/**
 * hexa_upper_helper - Recursively fills buffer with hexadecimal digits.
 * @number: The number to convert.
 * @str: The buffer to write characters into.
 *
 * Return: Pointer to the next available character in the buffer.
 *
 * Description: Uses recursion to ensure the digits are written in the
 *              correct order. Assumes buffer is pre-allocated
 *              and large enough.
 */
char *hexa_upper_helper(unsigned int number, char *str)
{
	char *hexa_value = "0123456789ABCDEF";

	if (number == 0)
		return (str);

	str = hexa_upper_helper(number / 16, str);
	*str = hexa_value[number % 16];
	return (str + 1);
}


/**
 * hexa_lower_to_string - Converts an unsigned int to a lowercase
 * hexadecimal string.
 * @args: A va_list containing the unsigned int to convert.
 *
 * Return: Pointer to a newly allocated string representing the hexadecimal
 *         form of the number in lowecase, or NULL if allocation fails.
 *
 * Description: Returns "0" if the number is 0.
 *              Caller is responsible for freeing the returned string.
 */
char *hexa_lower_to_string(va_list args)
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

	ptr = hexa_lower_helper(number, str);
	*ptr = '\0';

	return (str);
}


/**
 * hexa_lower_helper - Recursively fills buffer
 * with lowercase hexadecimal digits.
 * @number: The number to convert.
 * @str: The buffer to write characters into.
 *
 * Return: Pointer to the next available character in the buffer.
 *
 * Description: Uses recursion to ensure the digits are written in the
 *              correct order. Assumes buffer is pre-allocated
 *              and large enough.
 */
char *hexa_lower_helper(unsigned int number, char *str)
{
	char *hexa_value = "0123456789abcdef";

	if (number == 0)
		return (str);

	str = hexa_lower_helper(number / 16, str);
	*str = hexa_value[number % 16];
	return (str + 1);
}
