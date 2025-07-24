#include "main.h"
#include <stdlib.h>
/**
 * apply_precision - applies precision formatting based on specifier type
 * @fmt: pointer to format_specifier_t containing precision and specifier info
 * @str: string to be formatted according to precision rules
 *
 * Description:
 *   - If the specifier is 's', applies string precision truncation.
 *   - If the specifier is an integer type ('d', 'i', 'u', 'x', 'X', 'o', 'b'),
 *     applies integer precision formatting with leading zeros as needed.
 *   - Otherwise, returns the original string unchanged.
 *
 * Return: pointer to a newly allocated formatted string or the original string.
 *         Returns NULL if any malloc call inside handlers fails.
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
 * apply_flags - Applies all relevant format flags to the given string.
 * @fmt: Pointer to the format specifier structure containing flags and specifier.
 * @str: The string to which flags will be applied. It is assumed to be dynamically allocated.
 *
 * Applies the flags in the following order:
 *   1. Hash (#) flag: adds prefixes like "0x" for hex.
 *   2. Plus (+) flag: adds a plus sign for positive numbers.
 *   3. Space ( ) flag: adds a space for positive numbers if plus flag is not set.
 *   4. Zero (0) flag: pads the string with zeros (considering prefixes).
 *   5. Minus (-) flag: left-justifies the string by adding spaces on the right.
 *
 * Return: Pointer to the newly allocated string with flags applied.
 *         Frees the original string and returns NULL on allocation failure.
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
 * apply_width - Applies minimum field width by padding the string with spaces
 *               on the left, if neither FLAG_ZERO nor FLAG_MINUS is set.
 * @fmt: Pointer to the format specifier structure containing flags and width.
 * @str: The string to apply width padding to (must be dynamically allocated).
 *
 * Return: Pointer to a new string padded with spaces if padding was needed,
 *         otherwise returns the original string.
 *         Returns NULL on memory allocation failure.
 *
 * Description:
 * This function checks if the width specified in the format specifier is greater
 * than the length of the input string, and if neither the ZERO nor MINUS flags
 * are set. If so, it allocates a new string and pads it with spaces on the left
 * to meet the width requirement, then copies the original string to the right.
 * The original string is freed before returning the new padded string.
 * If no padding is needed, the original string is returned unmodified.
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
 * apply_all - Applies precision, flags, and width formatting to a string.
 * @fmt: Pointer to the format specifier structure containing formatting info.
 * @str: The string to format (must be dynamically allocated).
 *
 * Return: Pointer to the newly formatted string on success,
 *         or NULL if any formatting step fails.
 *
 * Description:
 * This function applies formatting to the input string in the following order:
 * 1. Precision adjustments (e.g., truncating or padding numbers).
 * 2. Flags such as plus, space, zero, minus, and hash.
 * 3. Field width padding.
 * 
 * Each step may return a newly allocated string, and the previous string is freed.
 * If any step fails (returns NULL), the function immediately returns NULL.
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
