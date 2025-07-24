#include "main.h"

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
	unsigned int size = 0;
	unsigned long temp = 0;

	if (number == 0)
		return (2);

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
/**
 * _sizeoflong - Calculates the number of characters needed
 *               to represent a long integer as a string,
 *               including space for sign and null terminator.
 * @number: The long integer to measure.
 *
 * Return: The size (in bytes) required to store the string
 *         representation of the number, including the null byte.
 */
unsigned int _sizeoflong(long number)
{
	unsigned int size = 0;
	unsigned long temp = 0;

	if (number == 0)
		return (2);

	if (number < 0)
		size++;

	if (number < 0)
		temp = (unsigned long)(-number);
	else
		temp = (unsigned long)number;

	while (temp > 0)
	{
		temp /= 10;
		size++;
	}

	size++; /* for null terminator */
	return (size);
}

/**
 * _sizeofshort - Calculates the number of characters needed
 *                to represent a short integer as a string,
 *                including space for sign and null terminator.
 * @number: The short integer to measure.
 *
 * Return: The size (in bytes) required to store the string
 *         representation of the number, including the null byte.
 */
unsigned int _sizeofshort(short number)
{
	unsigned int size = 0;
	unsigned short temp = 0;

	if (number == 0)
		return (2);

	if (number < 0)
		size++;

	if (number < 0)
		temp = (unsigned short)(-number);
	else
		temp = (unsigned short)number;

	while (temp > 0)
	{
		temp /= 10;
		size++;
	}

	size++; /* for null terminator */
	return (size);
}

/**
 * _sizeofchar - Calculates the number of characters needed
 *               to represent a signed char as a string,
 *               including space for sign and null terminator.
 * @number: The signed char to measure.
 *
 * Return: The size (in bytes) required to store the string
 *         representation of the number, including the null byte.
 */
unsigned int _sizeofchar(signed char number)
{
	unsigned int size = 0;
	unsigned char temp = 0;

	if (number == 0)
		return (2);

	if (number < 0)
		size++;

	if (number < 0)
		temp = (unsigned char)(-number);
	else
		temp = (unsigned char)number;

	while (temp > 0)
	{
		temp /= 10;
		size++;
	}

	size++; /* for null terminator */
	return (size);
 }


