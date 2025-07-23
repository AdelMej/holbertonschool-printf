#include "main.h"
#include <stdarg.h>
#include <stdlib.h>
/* Function declarations */
char *octal_helper(unsigned int number, char *str);

/**
 * octal_to_string - Converts an unsigned int to an octal string
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
char *octal_to_string(va_list args)
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

	ptr = octal_helper(number, str);
	*ptr = '\0';

	return (str);
}


/**
 * octal_helper - Recursively fills buffer with octal digits
 * @number: The unsigned integer to convert to octal
 * @str: The buffer to write the characters into
 *
 * This function converts the given number to its octal representation
 * using recursion and writes the digits in the correct order into the
 * provided buffer. The buffer must be pre-allocated and large enough.
 *
 * Return: Pointer to the next available position in the buffer
 */
char *octal_helper(unsigned int number, char *str)
{
	char *hexa_value = "0123456789abcdef";

	if (number == 0)
		return (str);

	str = octal_helper(number / 8, str);
	*str = hexa_value[number % 8];
	return (str + 1);
}
