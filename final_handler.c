#include "main.h"

char *apply_precision(format_specifier_t *fmt, char *str)
{
	unsigned int i, j, size = 0;
	char *new_str;
	char *ptr;
	const char *int_types = "diuxXob";

	if (fmt->specifier == 's')
	{
		size = _strlen(str);
		if (fmt->precision < size)
		{
			new_str = malloc(fmt->precision + 1);
			if (new_str == NULL)
				return (NULL);

			for (i = 0; i < fmt->precision; i++)
			{
				new_str[i] = str[i];
			}
			new_str[i] = '\0';
			free(str);
			return (new_str);
		}
		else
		{
			return (str);
		}
	}
	for (i = 0; int_types[i] != '\0'; i++)
	{
		if (int_types[i] == fmt->specifier)
		{
			size = _strlen(str);
			if (fmt->precision == 0)
			{
				new_str = malloc(1);
				new_str[0] = '\0';
				free(str);
				return (new_str);
			}
			if (fmt->precision > _strlen(str))
			{
				new_str = malloc(fmt->precision + 1);
				if (new_str == NULL)
					return (NULL);
				ptr = new_str;
				if (str[0] == '-')
				{
					*ptr = '-';
					ptr++;
				}
				while (i < fmt->precision - _strlen(str))
				{
					*ptr = '0';
					ptr++;
				}
				for (i = 0; str[i] != '\0'; i++)
				{
					*ptr = str[i];
					ptr++;
				}
				*ptr = '\0';
				free(str);
				return (new_str);
			}
		}
	}

	return (str);
}
char *apply_flags(format_specifier_t *fmt, char *str)
{

}
char *apply_width(format_specifier_t *fmt, char *str)
{

}
char *apply_all(format_specifier_t *fmt, char *str)
{
	str = apply_precision(str);
	str = apply_flags(str);
	str = apply_width(str);
)
