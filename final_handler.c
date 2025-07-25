#include "main.h"
#include <stdlib.h>
/**
 * apply_precision - Applies precision formatting
 * to a given string based on specifier.
 * @fmt: Pointer to a format_specifier_t struct containing format info.
 * @str: The string to be processed
 * (usually representing a formatted argument).
 *
 * Return: A newly allocated string with precision applied,
 *         or the original string if no change is needed.
 *         The original string is freed if a new one is allocated.
 */
char *apply_precision(format_specifier_t *fmt, char *str)
{
	unsigned int i;
	const char *int_types = "diuxXob";

	if (fmt->specifier == 's')
	{
		return (string_precision_handler(fmt, str));
	}
	for (i = 0; int_types[i] != '\0'; i++)
	{
		if (int_types[i] == fmt->specifier)
		{
			return (int_precision_handler(fmt, str));
		}
	}

	return (str);
}

/**
 * apply_flags - Applies format flags to a given formatted string.
 * @fmt: Pointer to a format_specifier_t struct containing format info.
 * @str: The string to apply the flags to.
 *
 * Return: A newly allocated string with the flags applied,
 *         or NULL on failure.
 *         The original string may be freed during the process.
 */
char *apply_flags(format_specifier_t *fmt, char *str)
{
	if (str == NULL)
		return (NULL);

	str = apply_hash(fmt, str);
	str = apply_plus(fmt, str);
	str = apply_space(fmt, str);
	str = apply_zero(fmt, str);
	str = apply_minus(fmt, str);
	return (str);
}

/**
 * apply_width - Applies the minimum field width to a formatted string.
 * @fmt: Pointer to a format_specifier_t struct containing format info.
 * @str: The string to apply the width to.
 *
 * Return: A newly allocated string with padding added if necessary,
 *         or the original string if no padding is needed.
 *         Returns NULL on memory allocation failure.
 */
char *apply_width(format_specifier_t *fmt, char *str)
{
	unsigned int padding = 0, i, j;
	int size = _strlen(str);
	char *new_str;

	if (str == NULL)
		return (NULL);

	if (!(fmt->flags & FLAG_ZERO || fmt->flags & FLAG_MINUS) && fmt->width > size)
	{
		padding = fmt->width - size;

		new_str = malloc(size + padding + 1);
		if (new_str == NULL)
			return (NULL);

		for (i = 0; i < padding; i++)
			new_str[i] = ' ';

		for (j = 0; str[j] != '\0'; j++)
		{
			new_str[i + j] = str[j];
		}
		new_str[i + j] = '\0';
		free(str);
		return (new_str);
	}
	return (str);
}

/**
 * apply_all - Applies precision, width, and flags to a formatted string.
 * @fmt: Pointer to a format_specifier_t struct containing format info.
 * @str: The string to format.
 *
 * Return: A newly allocated formatted string, or NULL on failure.
 */
char *apply_all(format_specifier_t *fmt, char *str)
{
	if (str == NULL)
		return (NULL);

	str = apply_precision(fmt, str);
	if (str == NULL)
		return (NULL);

	str = apply_flags(fmt, str);
	if (str == NULL)
		return (NULL);

	str = apply_width(fmt, str);
	if (str == NULL)
		return (NULL);

	return (str);
}
