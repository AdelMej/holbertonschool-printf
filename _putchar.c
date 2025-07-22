#include <stdio.h>
#include <unistd.h>

static char buffer[1024];
static int index;

/**
 * _putchar - Writes a character to stdout using a buffer.
 * @c: The character to write.
 *
 * Description: Buffers characters until the buffer is full (1024 bytes),
 * then writes the buffer to stdout in a single write call to optimize I/O.
 *
 * Return: On success, returns 1.
 */
int _putchar(char c)
{
	buffer[index++] = c;

	if (index == 1024)
	{
		write(1, buffer, 1024);
		index = 0;
	}
	return (1);
}

/**
 * _putchar_flush - Flushes the buffer by writing any remaining characters
 * to stdout.
 *
 * Description: Should be called at the end of the program or before exiting
 * to ensure all buffered characters are written to stdout.
 */
void _putchar_flush(void)
{
	if (index > 0)
	{
		write(1, buffer, index);
		index = 0;
	}
}
