#include "main.h"
#include <stdlib.h>
#include <stdarg.h>
/**
* get_handler_function - a function that returns a pointer to
* a function that returns an int and takes a va_list in parameter
*
* @specifier: the specifier to test
* Return: the function pointer on success
* NULL on fail
*/
handler_func_t get_handler_function(char specifier)
{
	unsigned int i;

	static factory_t factory[] = {
		{'c', char_to_string_handler},
		{'d', int_to_string_handler},
		{'i', int_to_string_handler},
		{'s', string_handler},
		{'b', binary_to_string_handler},
		{'u', uint_to_string_handler},
		{'x', hexa_lower_to_string_handler},
		{'X', hexa_upper_to_string_handler},
		{'o', octal_to_string_handler},
		{'S', custom_string_handler},
		{'p', pointer_handler},
		{'r', reversed_string_handler},
		{'R', rot13_string_handler},
		{'\0', NULL}
	};

	for (i = 0; factory[i].specifier != '\0'; i++)
		if (factory[i].specifier == specifier)
			return (factory[i].handler);

	return (NULL);
}
