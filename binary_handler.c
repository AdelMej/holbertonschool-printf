#include "main.h"
#include <stdlib.h>
#include <stdarg.h>
/*function delaration */
char *binary_helper(unsigned int number, char *str);

/**
 * binary_to_string - Converts an unsigned int to a binary string.
 * @args: A va_list containing the unsigned int to convert.
 *
 * Return: Pointer to a newly allocated string representing the binary
 *         form of the number, or NULL if memory allocation fails.
 *
 * Description: If the number is zero, returns a string "0".
 *              Otherwise, calculates the required string size,
 *              allocates memory, and fills it with the binary digits.
 *              The caller is responsible for freeing the returned string.
 */
char *binary_to_string(va_list args)
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

	ptr = binary_helper(number, str);
	*ptr = '\0';

	return (str);
}

/**
 * binary_helper - Recursively converts an unsigned integer to binary string.
 * @number: The unsigned integer to convert.
 * @str: Pointer to the current position in the output string buffer.
 *
 * Return: void
 *
 * Note: This function appends the binary digits to `str`
 * as characters ('0' or '1'),
 * increments the length accordingly, and assumes `str` has enough space.
 * The pointer `str` is incremented as the recursion unwinds to fill digits.
 */
char *binary_helper(unsigned int number, char *str)
{
	if (number == 0)
		return (str);

	str = binary_helper(number / 2, str);
	*str = (number % 2) + '0';
	return (str + 1);
}
