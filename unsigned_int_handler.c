#include "main.h"
#include <stdarg.h>
#include <stdlib.h>

/* Function declarations */
unsigned int _sizeofuint(unsigned int number);

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
char *uint_to_string(va_list args)
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
 * _sizeofuint - Calculates the length of an unsigned int number as a string.
 * @number: The unsigned int number to calculate size for.
 *
 * Return: The size needed to represent the number as a string including
 *         the null terminator.
 *
 * Description: Returns 2 if number is 0 (one digit plus null terminator),
 *              otherwise returns the number of digits plus one for the
 *              null terminator.
 */
unsigned int _sizeofuint(unsigned int number)
{
	unsigned int temp, size = 0;

	if (number == 0)
		return (2);

	temp = number;

	while (temp > 0)
	{
		temp /= 10;
		size++;
	}

	return (size + 1); /* for null terminator */
}
