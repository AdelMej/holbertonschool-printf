#ifndef MY_PRINTF_MAIN_H
#define MY_PRINTF_MAIN_H
#include <stdarg.h>
#include <stddef.h>

/* Flag constants for format_specifier.flags bitmask */
#define FLAG_MINUS  (1 << 0) /* '-' flag: left-justify */
#define FLAG_PLUS   (1 << 1) /* '+' flag: force sign */
#define FLAG_ZERO   (1 << 2) /* '0' flag: zero padding */
#define FLAG_SPACE  (1 << 3) /* ' ' flag: space if no sign */
#define FLAG_HASH   (1 << 4) /* '#' flag: alternate form */

/**
 * struct format_factory - Associates format specifiers with handler functions
 * @specifier: The format specifier character (e.g., 'd', 's', 'c')
 * @print: Pointer to the function that handles printing for this specifier
 *
 * Description: This structure is used to map a format specifier character
 * to its corresponding printing function. It is used in the custom _printf
 * implementation to dispatch the correct function based on the specifier.
 */
struct format_factory
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
	int width;
	char length[3];
	int precision;
	char specifier;
};

/* --- typedefs --- */
typedef struct format_factory factory_t;
typedef struct format_specifier format_specifier_t;
typedef char *(*print_func_t)(va_list);

/* --- Core printf interface --- */
int _printf(const char *format, ...);
int _putchar(char c);
void _putchar_flush(void);

/* --- Format handler helpers --- */
print_func_t get_print_function(char c);
char *format_handler(char specifier, va_list args);
const char *flag_handler(const char *format_ptr, format_specifier_t *info);
void init_format_info(format_specifier_t *info);
const char *width_handler(const char *str, format_specifier_t *format, va_list *args);

/* --- Printing functions --- */
/* Characters and strings */
char *char_to_string(va_list args);
char *string_cpy(va_list args);
char *custom_string_cpy(va_list args);
unsigned int _strlen(char *str);

/* Numbers */
char *int_to_string(va_list args);
char *uint_to_string(va_list args);
char *binary_to_string(va_list args);
char *octal_to_string(va_list args);
char *hexa_upper_to_string(va_list args);
char *hexa_lower_to_string(va_list args);
char *pointer_to_string(va_list args);

#endif
