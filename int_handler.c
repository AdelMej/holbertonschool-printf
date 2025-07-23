#include "main.h"
#include <stdlib.h>

/* Function declarations */
unsigned int _sizeofint(int number);

/**
 * char_to_string - Converts a character from a va_list to a string.
 * @args: A va_list containing the character to convert.
 *
 * Return: Pointer to a newly allocated string containing the character,
 *         or NULL if memory allocation fails.
 *
 * Note: The caller is responsible for freeing the returned string.
 */
char *char_to_string(va_list args)
{
	char c = va_arg(args, int);
	char *str;

	str = malloc(2);
	if (str == NULL)
		return (NULL);

	str[0] = c;
	str[1] = '\0';
	return (str);
}

/**
 * int_to_string - Converts an integer from a va_list to a string.
 * @args: A va_list containing the integer to convert.
 *
 * Return: Pointer to the newly allocated string representing the integer,
 *         or NULL if memory allocation fails.
 *
 * Description: This function retrieves an integer from the va_list,
 *              allocates sufficient memory using _sizeofint to store
 *              the string representation including sign and null terminator,
 *              then converts the integer to its string form.
 *              Handles zero and negative numbers correctly.
 *              The caller is responsible for freeing the returned string.
 */
char *int_to_string(va_list args)
{
	int number = va_arg(args, int);
	char *str;
	unsigned int size, temp, i;

	size = _sizeofint(number);
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
	if (number < 0)
	{
		temp = (unsigned int)(-(long)number);
		str[0] = '-';
	}
	else
	{
		temp = (unsigned int)number;
	}

	for (i = 0; temp > 0; i++)
	{
		str[size - i - 2] = (temp % 10) + '0';
		temp /= 10;
	}

	return (str);
}

/**
 * _sizeofint - calculates the number of characters needed
 *             to represent an integer as a string,
 *             including space for the sign and null terminator.
 * @number: the integer to calculate size for.
 *
 * Return: the size in bytes needed for allocation.
 */
unsigned int _sizeofint(int number)
{
	unsigned int temp, size;

	if (number == 0)
		size = 1;
	else
		size = 0;

	if (number < 0)
		size++;

	if (number < 0)
		temp = (unsigned int)(-(long)number);
	else
		temp = (unsigned int)number;

	while (temp > 0)
	{
		temp /= 10;
		size++;
	}
	size++;

	return (size);
}
