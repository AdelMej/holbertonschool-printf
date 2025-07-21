#include <stdio.h>

/**
* _putchar - a function to print a character
* @c: a character
*
* Return: void
*/
void _putchar(char c)
{
	return (write(1, &c, 1));
}
