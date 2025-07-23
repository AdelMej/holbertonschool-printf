#include "_string.h"

/**
 * _strlen - calculates the length of a null-terminated string.
 * @str: pointer to the string.
 *
 * Return: the number of characters in the string,
 *         excluding the null terminator.
 */
unsigned int _strlen(char *str)
{
	unsigned int len = 0;

	while (str[len] != '\0')
		len++;

	return (len);
}
