#include <stdio.h>
#include <unistd.h>

/**
* _putchar - a function to print a character
* @c: a character
*
* Return: void
*/
int _putchar(char c)
{
	return (write(1, &c, 1));
}
