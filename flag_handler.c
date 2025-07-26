#include "main.h"
#include <stdlib.h>

/**
 * apply_zero - Applies zero-padding to the formatted string if needed.
 * @fmt: Pointer to a format_specifier_t struct containing format info.
 * @str: The string to pad.
 *
 * Return: A new string with zero-padding applied, or the original string.
 */
char *apply_zero(format_specifier_t *fmt, char *str)
{
	int prefix_length = 0, i, j, k, padding = 0;
	int size = _strlen(str);
	char *new_str;

	if (fmt->width <= size)
		return (str);

	if (fmt->precision >= 0 || (fmt->flags & FLAG_MINUS))
	{
		return (str);
	}
	else if (fmt->flags & FLAG_ZERO)
	{
		if (str[0] == '+' || str[0] == '-')
			prefix_length = 1;
		else if (str[0] == '0' &&
				(str[1] == 'b' || str[1] == 'x' || str[1] == 'X'))
			prefix_length = 2;
		else if (fmt->specifier == 'o' && str[0] == '0')
			prefix_length = 1;

		padding = fmt->width - size;
		new_str = malloc(size + padding + 1);
		if (new_str == NULL)
			return (NULL);

		for (i = 0; i < prefix_length; i++) /* copy prefix */
			new_str[i] = str[i];

		for (j = 0; j < padding; j++) /* zero padding */
			new_str[i + j] = '0';

		for (k = 0; str[i + k] != '\0'; k++) /* copy the rest of the string */
			new_str[i + j + k] = str[i + k];

		new_str[i + j + k] = '\0';
		free(str);
		return (new_str);
	}
	return (str);
}

/**
 * apply_minus - Applies left-justification padding if '-' flag is set.
 * @fmt: Pointer to a format_specifier_t struct containing format info.
 * @str: The string to pad and left-align.
 *
 * Return: A newly allocated left-aligned string with spaces padded,
 *         or the original string if no action is needed.
 */
char *apply_minus(format_specifier_t *fmt, char *str)
{
	int size = 0;
	unsigned int padding = 0, i, j;
	char *new_str;

	if (str == NULL)
		return (NULL);

	size = _strlen(str);
	if (fmt->flags & FLAG_MINUS && !(fmt->flags & FLAG_ZERO))
	{
		if (fmt->width > size)
			padding = fmt->width - size;
		else
			padding = 0;

		new_str = malloc(size + padding + 1);
		if (new_str == NULL)
			return (NULL);

		for (i = 0; str[i] != '\0'; i++)
			new_str[i] = str[i];

		for (j = 0; j < padding; j++)
			new_str[i + j] = ' ';

		new_str[i + j] = '\0';
		free(str);
		return (new_str);
	}

	return (str);
}

/**
 * apply_plus - Adds a plus sign to positive integers if '+' flag is set.
 * @fmt: Pointer to a format_specifier_t struct containing format info.
 * @str: The string representation of the number to modify.
 *
 * Return: A newly allocated string with a '+' prefix if applicable,
 *         or the original string if not modified.
 */
char *apply_plus(format_specifier_t *fmt, char *str)
{
	unsigned int i = 0;
	int size = 0;
	char *new_str;

	if ((fmt->specifier == 'd' || fmt->specifier == 'i')
		&& fmt->flags & FLAG_PLUS)
	{
		size = _strlen(str);
		if (str[0] != '-')
		{
			new_str = malloc(size + 2);
			if (new_str == NULL)
				return (NULL);

			new_str[0] = '+';
			for (i = 0; str[i] != '\0'; i++)
				new_str[i + 1] = str[i];

			new_str[i + 1] = '\0';
			free(str);
			return (new_str);
		}
	}

	return (str);
}

/**
 * apply_space - Adds a space before positive integers if the space flag is set
 *               and the plus flag is not.
 * @fmt: Pointer to the format_specifier_t struct with flags and specifier.
 * @str: String representation of the number to modify.
 *
 * Return: A newly allocated string with space prepended if applicable,
 *         or the original string if unchanged. Returns NULL on malloc failure.
 *         Frees original string if a new one is returned.
 */
char *apply_space(format_specifier_t *fmt, char *str)
{
	unsigned int size = 0, i = 0;
	char *new_str;

	if (str == NULL)
		return (NULL);

	if ((fmt->specifier == 'd' || fmt->specifier == 'i')
		&& (fmt->flags & FLAG_SPACE)
		&& !(fmt->flags & FLAG_PLUS))
	{
		size = _strlen(str);
		if (str[0] != '-')
		{
			new_str = malloc(size + 2);
			if (new_str == NULL)
				return (NULL);

			new_str[0] = ' ';
			for (i = 0; str[i] != '\0'; i++)
				new_str[i + 1] = str[i];

			new_str[i + 1] = '\0';
			free(str);
			return (new_str);
		}
	}

	return (str);
}

/**
 * apply_hash - Applies the '#' flag by prepending the appropriate prefix
 *              to octal, hexadecimal, or binary values.
 * @fmt: Pointer to the format_specifier_t
 * struct containing flags and specifier.
 * @str: String representing the number to modify.
 *
 * Return: A newly allocated string with the prefix prepended if applicable,
 *         or the original string if no change is needed or on malloc failure.
 *         Frees the original string if a new one is returned.
 */
char *apply_hash(format_specifier_t *fmt, char *str)
{
	unsigned int size = 0, i = 0, to_malloc = 0;
	char *new_str;

	if ((fmt->flags & FLAG_HASH) &&
		(fmt->specifier == 'o'
		|| fmt->specifier == 'x'
		|| fmt->specifier == 'X'
		|| fmt->specifier == 'b'))
	{
		size = _strlen(str);
		if (size == 1 && str[0] == '0')
			return (str);

		if (fmt->specifier == 'o')
			to_malloc = 1;
		else
			to_malloc = 2;

		new_str = malloc(size + to_malloc + 1);
		if (new_str == NULL)
			return (NULL);

		new_str[0] = '0';
		if (fmt->specifier == 'x')
			new_str[1] = 'x';
		else if (fmt->specifier == 'X')
			new_str[1] = 'X';
		else if (fmt->specifier == 'b')
			new_str[1] = 'b';

		for (i = 0; str[i] != '\0'; i++)
			new_str[i + to_malloc] = str[i];

		new_str[i + to_malloc] = '\0';
		free(str);
		return (new_str);
	}

	return (str);
}
