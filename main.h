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
 * struct format_specifier - Holds formatting flags and options
 * @flags: Bitmask of active flags.
 * @width: Field width.
 * @length: Length modifier string.
 * @precision: Precision value or -1 if not set.
 * @specifier: Conversion specifier character.
 */
struct format_specifier
{
	int flags; /* bitmask for flags like '-', '+', '0', ' ', '#' */
	int width;
	char length[3];
	int precision;
	char specifier;
};
typedef struct format_specifier format_specifier_t;

typedef char *(*handler_func_t)(format_specifier_t *, va_list);

/**
 * struct factory - Maps a format specifier to its handler function
 * @specifier: The format specifier character (e.g., 'd', 's', 'X')
 * @handler: Pointer to the function that handles the specifier
 *
 * This struct associates a single format specifier with the function
 * that will process and print the corresponding argument.
 */
struct factory {
	char specifier;
	handler_func_t handler;
};
typedef struct factory factory_t;

/* --- Core printf interface --- */
int _printf(const char *format, ...);
int _putchar(char c);
void _putchar_flush(void);

/* --- Format handler helpers --- */
handler_func_t get_handler_function(char specifier);
char *format_handler(format_specifier_t *format_specifier, va_list args);
const char *flag_handler(const char *format_ptr, format_specifier_t *info);
void init_format_info(format_specifier_t *info);
const char *width_handler(const char *str,
						  format_specifier_t *format,
						  va_list *args);
const char *length_handler(const char *str, format_specifier_t *format);

/* --- Printing functions --- */
/* Characters and strings */
char *char_handler(format_specifier_t *format_specifier, va_list args);
char *string_handler(format_specifier_t *format_specifier, va_list args);
char *custom_string_handler(format_specifier_t *format_specifier, va_list args);
char *reversed_string_handler(format_specifier_t *fmt, va_list args);
char *rot13_string_handler(format_specifier_t *fmt, va_list args);

/* --- string Helpers --- */
char *_strdup(char *str);
unsigned int _strlen(char *str);

/* Numbers */
/* --- int to string --- */
char *int_to_string_handler(format_specifier_t *format_specifier,
							va_list args);
char *int_to_string_default(va_list args);
char *int_to_string_l(va_list args);
char *int_to_string_h(va_list args);
char *int_to_string_hh(va_list args);

/* --- unsigned int to string --- */
char *uint_to_string_handler(format_specifier_t *format_specifier,
							 va_list args);
char *uint_to_string_default(va_list args);
char *uint_to_string_l(va_list args);
char *uint_to_string_h(va_list args);
char *uint_to_string_hh(va_list args);

/* --- binary to string --- */
char *binary_to_string_handler(format_specifier_t *format_specifier,
							   va_list args);
char *binary_to_string_default(va_list args);
char *binary_to_string_l(va_list args);
char *binary_to_string_h(va_list args);
char *binary_to_string_hh(va_list args);

/* --- octal to string --- */
char *octal_to_string_handler(format_specifier_t *format_specifier,
							  va_list args);
char *octal_to_string_default(va_list args);
char *octal_to_string_l(va_list args);
char *octal_to_string_h(va_list args);
char *octal_to_string_hh(va_list args);

/* --- hexa to string --- */
/* --- hexa upper --- */
char *hexa_upper_to_string_handler(format_specifier_t *format_specifier,
								   va_list args);
char *hexa_upper_to_string_default(va_list args);
char *hexa_upper_to_string_l(va_list args);
char *hexa_upper_to_string_h(va_list args);
char *hexa_upper_to_string_hh(va_list args);

/* --- hexa lower --- */
char *hexa_lower_to_string_handler(format_specifier_t *format_specifier,
								   va_list args);
char *hexa_lower_to_string_default(va_list args);
char *hexa_lower_to_string_l(va_list args);
char *hexa_lower_to_string_h(va_list args);
char *hexa_lower_to_string_hh(va_list args);

/* --- pointer to string --- */
char *pointer_handler(format_specifier_t *format_specifier,
						va_list args);

/* --- Helper --- */
char *convert_base(unsigned int number,
				   char *str, int base, const char *values);

/* --- int helpers --- */
unsigned int _sizeofint(int number);
unsigned int _sizeoflong(long number);
unsigned int _sizeofshort(short number);
unsigned int _sizeofchar(signed char number);

/* --- unsigned int helpers --- */
unsigned int _sizeofuint(unsigned int number);
unsigned int _sizeofulong(unsigned long number);
unsigned int _sizeofushort(unsigned short number);
unsigned int _sizeofuchar(unsigned char number);

/* --- final processing line --- */
char *apply_precision(format_specifier_t *fmt, char *str);
char *string_precision_handler(format_specifier_t *fmt, char *str);
char *int_precision_handler(format_specifier_t *fmt, char *str);
char *apply_all(format_specifier_t *fmt, char *str);

/* --- flags helpers --- */
char *apply_zero(format_specifier_t *fmt, char *str);
char *apply_minus(format_specifier_t *fmt, char *str);
char *apply_plus(format_specifier_t *fmt, char *str);
char *apply_space(format_specifier_t *fmt, char *str);
char *apply_hash(format_specifier_t *fmt, char *str);

#endif /* MY_PRINTF_MAIN_H */
