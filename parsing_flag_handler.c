#include "main.h"

/**
 * flag_handler - Parses and sets format flags from a format string
 * @str: Pointer to the character after '%' in the format string
 * @format: Pointer to a struct holding the flag bitmask
 *
 * Description: This function reads characters from the format string
 * starting after the '%' character and checks for any valid format
 * flags ('+', '-', '0', ' ', '#'). If any are found, their
 * corresponding bits are set in the format->flags field. The function
 * stops parsing once a non-flag character or the null terminator is
 * reached.
 *
 * Return: Pointer to the first character in the format string that
 * is not a flag (or to the null terminator if the end is reached).
 */
const char *flag_handler(const char *str, format_specifier_t *format)
{
	int is_valid_flag = 1;
	char *valid_flags = "+-0# ";
	unsigned int i;

	while (is_valid_flag)
	{
		if (*str == '\0')
			break;

		is_valid_flag = 0;
		for (i = 0; valid_flags[i] != '\0'; i++)
		{
			if (valid_flags[i] == *str)
			{
				is_valid_flag = 1;
				break;
			}
		}
		if (!is_valid_flag)
			break;
		if (*str == '+')
			format->flags |= FLAG_PLUS;
		else if (*str == '-')
			format->flags |= FLAG_MINUS;
		else if (*str == '0')
			format->flags |= FLAG_ZERO;
		else if (*str == ' ')
			format->flags |= FLAG_SPACE;
		else if (*str == '#')
			format->flags |= FLAG_HASH;

		str++;
	}

	return (str);
}
