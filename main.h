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
int print_char(va_list args);

/* a function to print a string with a va_list */
int print_string(va_list args);

/* a function to print a number with a va_list */
int print_number(va_list args);

/* a function to print an unsigned int with a va_list */
int print_unsigned_int(va_list args);

/* a function to print a binary with va_list */
int print_binary(va_list args);

/* a function to print an octale with va_list */
int print_octale(va_list args);

/* a function to print an hexadecimal uppercase with va_list */
int print_hexa_upper(va_list args);

/* a function to print an hexadecimal lowercase with va_list */
int print_hexa_lower(va_list args);

/* a function to print a custom specifier %S with va_list */
int custom_print_string(va_list args);
#endif
