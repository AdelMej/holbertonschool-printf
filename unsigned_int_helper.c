#include "main.h"

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

/**
 * _sizeofulong - Calculates the number of characters needed
 *               to represent an unsigned long integer as a string,
 *               including the null terminator.
 * @number: The unsigned long integer to measure.
 *
 * Return: The size (in bytes) required to store the string
 *         representation of the number, including the null byte.
 */
unsigned int _sizeofulong(unsigned long number)
{
	unsigned int size = 0;
	unsigned long temp;

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

/**
 * _sizeofushort - calculates the number of characters needed
 *                 to represent an unsigned short integer as a string,
 *                 including space for the null terminator.
 * @number: the unsigned short integer to measure.
 *
 * return: the size (in bytes) required to store the string
 *         representation of the number, including the null byte.
 */
unsigned int _sizeofushort(unsigned short number)
{
	unsigned int size = 0;
	unsigned short temp;

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

/**
 * _sizeofuchar - Calculates the number of characters needed
 *               to represent an unsigned char as a string,
 *               including space for the null terminator.
 * @number: The unsigned char to measure.
 *
 * Return: The size (in bytes) required to store the string
 *         representation of the number, including the null byte.
 */
unsigned int _sizeofuchar(unsigned char number)
{
	unsigned int size = 0;
	unsigned char temp;

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

