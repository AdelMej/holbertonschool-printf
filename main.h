#ifndef PRINTF_MAIN_H
#define PRINTF_MAIN_H
#include <stdarg.h>

/* Flag constants for format_specifier.flags bitmask */
#define FLAG_MINUS  (1 << 0) /* '-' flag: left-justify */
#define FLAG_PLUS   (1 << 1) /* '+' flag: force sign */
#define FLAG_ZERO   (1 << 2) /* '0' flag: zero padding */
#define FLAG_SPACE  (1 << 3) /* ' ' flag: space if no sign */
#define FLAG_HASH   (1 << 4) /* '#' flag: alternate form */

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
	char *(*print)(va_list);
};

/**
 * struct format_specifier - Structure to hold format flags
 *                           for custom printf-like functions
 * @flags: Bitmask representing format flags such as '-', '+', '0', ' ', '#'
 *
 * Description: This struct is used to store formatting options parsed from
 * a format string. The flags are stored as a bitmask in the @flags field,
 * allowing efficient checking and combination of formatting behaviors.
 */
struct format_specifier
{
	int flags; /* bitmask for flags like '-', '+', '0', ' ', '#' */
};

typedef struct print_handler handler_t;
typedef struct format_specifier format_s_t;

/* defining a print_func_t for readability */
typedef char *(*print_func_t)(va_list);

/* function for getting a function pointer */
print_func_t get_print_function(char c);

/* a function to handle different format */
char *format_handler(char specifier, va_list args);

/* a function that mimic the behavior of printf */
int _printf(const char *format, ...);

/* a function to print a character */
int _putchar(char c);

/* a function to print a char with a va_list */
char *char_to_string(va_list args);

/* a function to print a string with a va_list */
char *string_cpy(va_list args);

/* a function to print a number with a va_list */
char *int_to_string(va_list args);

/* a function to print an unsigned int with a va_list */
char *uint_to_string(va_list args);

/* a function to print a binary with va_list */
char *binary_to_string(va_list args);

/* a function to print an octale with va_list */
char *octal_to_string(va_list args);

/* a function to print an hexadecimal uppercase with va_list */
char *hexa_upper_to_string(va_list args);

/* a function to print an hexadecimal lowercase with va_list */
char *hexa_lower_to_string(va_list args);

/* a function to print a custom specifier %S with va_list */
char *custom_string_cpy(va_list args);

/* a function to print a pointer in hexadecimal */
char *pointer_to_string(va_list args);

/* a function to print remaining buffered character */
void _putchar_flush(void);

#endif
