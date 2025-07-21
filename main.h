#ifndef PRINTF_MAIN_H
#define PRINTF_MAIN_H
#include <stdarg.h>

/**
* struct print_handler - a structure to handle printing
* depending on a specifier
* @specifier: a character defining the function to use
* @print: a function pointer to a function that handles printing
* the associated format
*/
struct print_handler
{
	char specifier;
	int (*print)(va_list);
};

typedef struct print_handler handler_t;

/* a function that mimic the behavior of printf */
int _printf(const char *format, ...);

/* a function to print a character */
void _putchar(char c);

/* a function to print a char with a va_list */
int print_char(va_list daVa);

/* a function to print a string with a va_list */
int print_string(va_list daVa);

/* a function to print a number with a va_list */
int print_number(va_list daVa);

#endif
