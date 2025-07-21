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

/* defining a print_func_t for readability */
typedef int (*print_func_t)(va_list);

/* function for getting a function pointer */
print_func_t get_print_function(char c);

/* a function to handle different format */
int format_handler(char specifier, va_list args);

/* a function that mimic the behavior of printf */
int _printf(const char *format, ...);

/* a function to print a character */
int _putchar(char c);

/* a function to print a char with a va_list */
int print_char(va_list daVa);

/* a function to print a string with a va_list */
int print_string(va_list daVa);

/* a function to print a number with a va_list */
int print_number(va_list daVa);

#endif
