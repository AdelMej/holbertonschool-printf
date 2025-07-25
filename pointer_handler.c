#include "main.h"
#include <stdarg.h>
#include <stdlib.h>

/* Function declarations */
char *pointer_helper(unsigned long address, char *str);
void nil_string(char *str);

/**
 * pointer_to_string - Converts a pointer to a hexadecimal string
 *                     prefixed with "0x".
 * @format_specifier: Pointer to format_specifier_t struct (unused).
 * @args: va_list containing the pointer to convert.
 *
 * Converts the pointer argument to a string representation of its
 * address in lowercase hexadecimal, prefixed by "0x". If the pointer
 * is NULL, returns a special nil string. Allocates memory for the
 * returned string, which must be freed by the caller.
 *
 * Return: Pointer to a newly allocated string representing the pointer,
 *         or NULL if memory allocation fails.
 */
char *pointer_to_string(format_specifier_t *format_specifier, va_list args)
{
	void *ptr = va_arg(args, void *);
	unsigned long address, temp;
	char *str, *strptr;
	unsigned int size;

	(void)format_specifier;
	address = (unsigned long)ptr;
	if (ptr == NULL)
	{
		str = malloc(6);
		if (str == NULL)
			return (NULL);
		nil_string(str);
		return (str);
	}

	if (address == 0)
	{
		str = malloc(3);
		if (str == NULL)
			return (NULL);
		str[0] = '0';
		str[1] = 'x';
		str[2] = '\0';
		return (str);
	}

	size = 2;
	temp = address;
	while (temp > 0)
	{
		temp /= 16;
		size++;
	}
	str = malloc(size + 1);
	if (str == NULL)
		return (NULL);

	str[0] = '0';
	str[1] = 'x';
	strptr = pointer_helper(address, str + 2);
	*strptr = '\0';

	return (str);
}

/**
 * pointer_helper - recursively converts an unsigned long to a hex string
 * @address: the unsigned long integer to convert
 * @str: pointer to the buffer where the hex digits will be written
 *
 * This function recursively converts the given address to its
 * hexadecimal representation and stores it in the buffer pointed to
 * by str. It writes digits starting from the most significant hex digit.
 *
 * Return: pointer to the position in the buffer after the last written digit
 */
char *pointer_helper(unsigned long address, char *str)
{
	static const char *tab_hexa = "0123456789abcdef";

	if (address == 0)
		return (str);

	str = pointer_helper(address / 16, str);
	*str = tab_hexa[address % 16];
	return (str + 1);
}

/**
 * nil_string - copies the string "(nil)" into the given buffer
 * @str: pointer to the buffer where the string will be copied
 *
 * This function copies the literal string "(nil)" including the
 * terminating null byte into the memory pointed to by @str.
 * The buffer must be large enough to hold at least 6 bytes.
 */
void nil_string(char *str)
{
	char *nil = "(nil)";
	unsigned int i;

	for (i = 0; nil[i] != '\0'; i++)
		str[i] = nil[i];

	str[i] = '\0';
}
