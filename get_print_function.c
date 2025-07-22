#include "main.h"
#include <stdlib.h>
#include <stdarg.h>
/**
* get_print_function - a function that returns a pointer to
* a function that returns an int and takes a va_list in parameter
*
* @c: the specifier to test
* Return: the function pointer on success
* NULL on fail
*/
print_func_t get_print_function(char c)
{
	unsigned int i;

	handler_t table_print[] = {
		{'c', print_char},
		{'s', print_string},
		{'d', print_number},
		{'i', print_number},
		{'b', print_binary},
		{'u', print_unsigned_int},
		{'o', print_octal},
		{'x', print_hexa_lower},
		{'X', print_hexa_upper},
		{'S', custom_print_string},
		{'\0', NULL}
	};

	for (i = 0; table_print[i].specifier != '\0'; i++)
		if (table_print[i].specifier == c)
			return (table_print[i].print);

	return (NULL);
}
